#include <iostream>
#include <fstream>
#include <stdio.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
std::string escape(const std::string &pattern);
int main(int argc, char *argv[])
{
	std::cout << argv[1] << std::endl;
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <config file>" << std::endl;
		return 1;
	}
	std::string configFile = argv[1];
	std::ifstream jfile(configFile);

	json data = json::parse(jfile);
	jfile.close();

	std::string tokenTableOutput;
	std::string FAFile;
	std::string symbolTable;
	std::string sourceFile;
	bool printFA;

	if (data.contains("config"))
	{
		json config = data["config"];
		if (config.contains("tokenOutPath"))
		{
			tokenTableOutput = config["tokenOutPath"];
		}
		if (config.contains("FAOutPath"))
		{
			FAFile = config["FAOutPath"];
		}
		if (config.contains("symbolTablePath"))
		{
			symbolTable = config["symbolTablePath"];
		}
		if (config.contains("sourceCodePath"))
		{
			sourceFile = config["sourceCodePath"];
		}
		if (config.contains("printFA"))
		{
			printFA = config["printFA"];
		}
	}
	else
	{
		std::cerr << "Configuration not exist" << std::endl;
	}
	std::string sourceCode = "zlex/src/main.cpp";
	std::string folderPath = sourceCode.substr(0, sourceCode.find_last_of("/\\"));
	std::filesystem::create_directories(folderPath);
	std::ofstream source(sourceCode, std::ios::trunc);

	// write include
	/*
		#include <iostream>
		#include "ZLex.hpp"
		#include "Token.hpp"
		#include <nlohmann/json.hpp>
		using json = nlohmann::json;
	*/
	source << "#include <iostream>" << std::endl;
	source << "#include \"ZLex.hpp\"" << std::endl;
	source << "#include \"Token.hpp\"" << std::endl;

	// write main
	/*
		int main(int argc, char *argv[])
		{
				std::string tokenTableOutput;
				std::string FAFile;
				std::string sourceFile;
				bool printFA;
	*/
	source << "int main()" << std::endl;
	source << "{" << std::endl;
	source << "    std::string tokenTableOutput=\"" << tokenTableOutput << "\";" << std::endl;
	source << "    std::string FAFile=\"" << FAFile << "\";" << std::endl;
	source << "    std::string symbolTable=\"" << symbolTable << "\";" << std::endl;
	source << "    std::string sourceFile=\"" << sourceFile << "\";" << std::endl;
	source << "    bool printFA=" << printFA << ";" << std::endl;

	// param process
	/*
		std::string folderPath = tokenTableOutput.substr(0, tokenTableOutput.find_last_of("/\\"));
		std::filesystem::create_directories(folderPath);
		std::ofstream tokenFile(tokenTableOutput, std::ios::trunc);
		folderPath = tokenTableOutput.substr(0, symbolTable.find_last_of("/\\"));
		std::filesystem::create_directories(folderPath);
		std::ofstream symbolTableFile(symbolTable, std::ios::trunc);
		ZLex zlex;
		std::string &yytext_ref = yytext;
	*/
	source << "    std::string folderPath = tokenTableOutput.substr(0, tokenTableOutput.find_last_of(\"/\\\\\"));" << std::endl;
	source << "    std::filesystem::create_directories(folderPath);" << std::endl;
	source << "    std::ofstream tokenFile(tokenTableOutput, std::ios::trunc);" << std::endl;
	source << "    folderPath = tokenTableOutput.substr(0, symbolTable.find_last_of(\"/\\\\\"));" << std::endl;
	source << "    std::filesystem::create_directories(folderPath);" << std::endl;
	source << "    std::ofstream symbolTableFile(symbolTable, std::ios::trunc);" << std::endl;
	source << "    ZLex zlex;" << std::endl;
	source << "    std::string &yytext_ref = yytext;" << std::endl;

	// write PAVec
	/*
		PAVec paVec1 = {
			{"[0-9]+", [&]() -> int
			{
				std::cout << yytext << std::endl;
				tokenFile << "$" << yytext << "$";
				tokenFile.flush();
				return 0;
			},
			"number"},
			// &用于捕获yytext和out
			{"[a-zA-Z]+", [&]() -> int
			{
				//  tokenFile << yytext << " ";
				//  tokenFile.flush();
				return 0;
			},
			"string"}};
	*/
	source << "    PAVec paVec = {" << std::endl;
	if (data.contains("grammar"))
	{
		json grammar = data["grammar"];
		for (const auto &item : grammar)
		{
			std::string pattern = item["pattern"];
			// pattern = escape(pattern);
			std::string action = item["action"];
			std::string type = item["note"];
			source << "        {\""
				   << pattern << "\", [&]() -> int" << std::endl;
			source << "        {" << std::endl;
			source << "            " << action << std::endl;
			source << "            return 0;" << std::endl;
			source << "        }," << std::endl;
			source << "        \"" << type << "\"}," << std::endl;
		}
		source << "    };" << std::endl;
	}

	// write zlex.buildAndAnalysis
	/*
		zlex.buildAndAnalysis(printFA, paVec1, FAFile, tokenFile, sourceFile);
	*/
	source << "    zlex.buildAndAnalysis(printFA, paVec, FAFile, tokenFile, sourceFile);" << std::endl;
	// write symbolTable
	/*
		SymbolTable::printSymbolTable(symbolTableFile);
	*/
	source << "    SymbolTable::printSymbolTable(symbolTableFile);" << std::endl;
	// write end
	source << "    return 0;" << std::endl;
	source << "}" << std::endl;
	source.close();
	return 0;
}
std::string escape(const std::string &pattern)
{
	std::string result;
	for (char c : pattern)
	{
		if (c == '\\')
		{
			result += '\\';
		}
		result += c;
	}
	return result;
}
