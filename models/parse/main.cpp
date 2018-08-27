#include "Parse.h"
//#include <vector>
int main()
{
	vector<string> g1;
	g1.push_back("spanishText_10000_15000");
	/*g1.push_back("spanishText_15000_20000");
	g1.push_back("spanishText_20000_25000");
	g1.push_back("spanishText_25000_30000");
	g1.push_back("spanishText_40000_45000");
	g1.push_back("spanishText_45000_50000");
	//g1.push_back("ejemplo");
	/*g1.push_back("spanishText_70000_75000");
	g1.push_back("spanishText_90000_95000");
	g1.push_back("spanishText_110000_115000");
	g1.push_back("spanishText_120000_125000");
	g1.push_back("spanishText_180000_185000");
	g1.push_back("spanishText_185000_190000");
	g1.push_back("spanishText_200000_205000");
	g1.push_back("spanishText_205000_210000");
	g1.push_back("spanishText_210000_215000");
	g1.push_back("spanishText_225000_230000");
	g1.push_back("spanishText_230000_235000");
	g1.push_back("spanishText_260000_265000");
	g1.push_back("spanishText_265000_270000");
	g1.push_back("spanishText_270000_275000");
	g1.push_back("spanishText_270000_275000");
	g1.push_back("spanishText_285000_290000");
	g1.push_back("spanishText_305000_310000");
	g1.push_back("spanishText_310000_315000");
	g1.push_back("spanishText_315000_320000");
	g1.push_back("spanishText_320000_325000");
	g1.push_back("spanishText_325000_330000");
	g1.push_back("spanishText_330000_335000");
	g1.push_back("spanishText_335000_340000");
	g1.push_back("spanishText_340000_345000");
	g1.push_back("spanishText_345000_350000");
	g1.push_back("spanishText_350000_355000");
	g1.push_back("spanishText_355000_360000");
	g1.push_back("spanishText_360000_365000");
	g1.push_back("spanishText_365000_370000");
	g1.push_back("spanishText_370000_375000");
	g1.push_back("spanishText_375000_380000");
	g1.push_back("spanishText_380000_385000");
	g1.push_back("spanishText_385000_390000");
	g1.push_back("spanishText_390000_395000");
	g1.push_back("spanishText_395000_400000");
	g1.push_back("spanishText_400000_405000");
	g1.push_back("spanishText_405000_410000");
	g1.push_back("spanishText_410000_415000");
	g1.push_back("spanishText_415000_420000");
	g1.push_back("spanishText_420000_425000");
	g1.push_back("spanishText_425000_430000");
	g1.push_back("spanishText_430000_435000");
	g1.push_back("spanishText_435000_440000");
	g1.push_back("spanishText_440000_445000");
	g1.push_back("spanishText_445000_450000");
	g1.push_back("spanishText_450000_455000");
	g1.push_back("spanishText_455000_460000");
	g1.push_back("spanishText_460000_465000");
	g1.push_back("spanishText_465000_470000");
	g1.push_back("spanishText_470000_475000");
	g1.push_back("spanishText_475000_480000");
	g1.push_back("spanishText_480000_485000");*/
	vector<string> result;
	for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
	{
		cout << *ir << endl;
		Parse *parse = new Parse(*ir);//spanishText_10000_15000
		result = parse->processFile();
		cout << endl;
	}

	getchar();
}
