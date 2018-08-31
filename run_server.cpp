#include "server_http.hpp"
#include <iostream>
#include <typeinfo>
#include <string>
#include <utility>
//Models for radixtree
#include "models/radix-tree/tree.h"
#include "models/parse/Parse.h"

// Added for the json-example
#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

// Added for the default_resource example
#include <algorithm>
#include <boost/filesystem.hpp>
#include <fstream>
#include <vector>
#define MAX_SIZE 10
#ifdef HAVE_OPENSSL
#include "crypto.hpp"
#endif

using namespace std;
using namespace boost::property_tree;


using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;



vector<string>* findSimilarWords(Tree* t, string word){
    vector<string> *dictionary = new vector<string>;
    t->findOptions(word, dictionary);
    return dictionary;
}

string vectorToJson(vector<string> *list, int maxSize){
    string json_string = "{\"words\":[";
    if(list->size() < maxSize)
        maxSize = list->size();
    
    for(int i = 0; i < maxSize; i++){
        json_string += "\""+(*list)[i]+"\"";
        if(i != maxSize-1)
            json_string += ",";
    }
    json_string += "]}";
    return json_string;
}

int main() {

    Tree *tree = new Tree();
    Parse *parse = new Parse("../../files/");
    parse->processFile();
    
    for(multimap<string, Word *>::iterator it = parse->words.begin(), end = parse->words.end(); it != end; it = parse->words.upper_bound(it->first)) {
        tree->add(it->first);
    }

    HttpServer server;
    server.config.port = 8090;


    server.resource["^/altavista$"]["GET"] = [](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        stringstream stream;
        SimpleWeb::CaseInsensitiveMultimap header;
        //stream << tree->get_json_string();
        stream << "test";
        response->write_get(stream,header);

    };
    
    /* http://localhost:8090/altavista/getOptions?word=test */
    server.resource["^/altavista/getOptions$"]["GET"] = [tree](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        stringstream stream;
        SimpleWeb::CaseInsensitiveMultimap header;

        try {
            string word;
            auto query_fields = request->parse_query_string();
            for(auto &field : query_fields)
                word = field.second;

            vector<string> *list = findSimilarWords(tree, word);
            stream << vectorToJson(list, MAX_SIZE);

            response->write_get(stream,header);
            delete list;

        } catch (const exception &e) {
            response->write(
                SimpleWeb::StatusCode::client_error_bad_request,
                e.what()
            );
        }
    };


    server.on_error = [](shared_ptr<HttpServer::Request> /*request*/, const SimpleWeb::error_code & /*ec*/) {
        // Handle errors here
        // Note that connection timeouts will also call this handle with ec set to SimpleWeb::errc::operation_canceled
    };

    cout << "WEB SERVER STARTED" << endl;
    thread server_thread([&server]() {
        // Start server
        server.start();
    });

    // Wait for server to start so that the client can connect
    this_thread::sleep_for(chrono::seconds(1));
    server_thread.join();
}
