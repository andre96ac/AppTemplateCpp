#pragma once
#include<string>
#include<algorithm>
#include<iostream>
#include<fstream>
#include <sstream>
#include<vector>

#include "Service.h"


class UtilsService: public Service
{
public:

	std::string ToUpperCase(std::string str) {
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		return str;
	}
	
	std::string ToLowerCase(std::string str) {
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		return str;
	}

	void throwException(std::string message) {
		throw std::invalid_argument(message);
	}

	template<typename T>
	std::string getjsonValueRep(T value) {
		if constexpr (std::is_same_v<T, std::string>) {
			return "\"" + value + "\"";
		}
		else if constexpr (std::is_same_v<T, int>) {
			return std::to_string(value);
		}
		else if constexpr (std::is_same_v<T, float>) {
			return std::to_string(value);
		}
		else if constexpr (std::is_same_v<T, double>) {
			return std::to_string(value);
		}
		else if constexpr (std::is_same_v<T, char>) {
			return "\"" + value + "\"";
		}
		else if constexpr (std::is_same_v<T, bool>) {
			return value ? "true" : "false";
		}
		else {
			throw std::invalid_argument("Funzione getConsoleLine chiamata con tipo non gestito");
		}
	}

	void saveToFile(std::string jsonData, std::string path) {
		std::ofstream exportFile;
		exportFile.open(path);
		exportFile << jsonData;
		exportFile.close();
	}

	std::string loadFromFile(std::string path) {
		std::string jsonData;

		std::ifstream t(path);
		std::stringstream buffer;
		buffer << t.rdbuf();
		jsonData = buffer.str();

		return jsonData;
	}

	std::vector<std::string> splitString(std::string s, std::string delimiter) {
		size_t pos_start = 0, pos_end, delim_len = delimiter.length();
		std::string token;
		std::vector<std::string> res;

		while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
			token = s.substr(pos_start, pos_end - pos_start);
			pos_start = pos_end + delim_len;
			res.push_back(token);
		}

		res.push_back(s.substr(pos_start));
		return res;
	}

	std::string removeFromString(std::string str, char car) {
		std::string sRet = str;
		sRet.erase(std::remove(sRet.begin(), sRet.end(), car), sRet.cend());
		return sRet;

	}

	void clear() {
		std::cout << "\033[2J\033[1;1H";
	}

	void wait() {
		std::cout << std::endl << "Premere invio per continuare..." << std::endl;
		getchar();
	}

	template <typename T>
	T getConsoleLine() {

		std::string retVar;
		std::getline(std::cin, retVar);

		if constexpr (std::is_same_v<T, std::string>) {
			return (T)retVar;
		}
		else if constexpr (std::is_same_v<T, int>) {
			return (T)std::stoi(retVar);
		}
		else if constexpr (std::is_same_v<T, float>) {
			return (T)std::stof(retVar);
		}
		else if constexpr (std::is_same_v<T, double>) {
			return (T)std::stod(retVar);
		}
		else if constexpr (std::is_same_v<T, char>) {
			const char* cstr = retVar.c_str();
			return (T)(*cstr);
		}
		else if constexpr (std::is_same_v<T, bool>) {
			if (retVar != "1" && retVar != "0") {
				throw std::invalid_argument("Impossibile convertire " + retVar + "in boolean");
			}
		}
		else {
			throw std::invalid_argument("Funzione getConsoleLine chiamata con tipo non gestito");
		}
	}

	




};

