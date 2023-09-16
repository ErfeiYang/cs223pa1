#ifndef DATA_H
#define DATA_H
#include "pa1.hpp"
#include "Node.hpp"

class Data {
protected:
	std::string CName;
	std::string CInfo;
	int CPoint;

public:

	Data() {
		CName = "";
		CInfo = "";
		CPoint = 0;
	}

	void Cname(std::string&);
	void Cinfo(std::string&);
	void Cpoint(int);
	std::string getCname() const;
	std::string getCinfo() const;
	int getCpoint()const;

	void operator=(const Data&);
	bool operator==(Data&) const;
};

void printMenu();

bool openF1(std::fstream&, std::string);

void Pvector(std::vector<Data>&);
void CopyFile(std::fstream& file, std::vector<Data>& cmdVec);
void pList(List<Node<Data>>&, std::vector<Data>&);
void display_all_commands(List<Node<Data>>& activeCmdList);
#endif