// LineManager.cpp
// Name: Mehran Alipour
// Seneca Student ID: 126778182
// Seneca email: malipour7@myseneca.ca
// Date of completion: Mar 21, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include "CustomerOrder.h"
#include "Workstation.h"
#include "LineManager.h"

using namespace std;

LineManager::LineManager(const std::string& myString, std::vector<Workstation*>& workSP, std::vector<CustomerOrder>& filcus) {
	ifstream input(myString);
	string mystatoin;
	size_t count = 0;
	if (!input)
	{
		std::cerr << "ERROR: Cannot open file [" << myString << "].\n";
	}
	do{
		if (input){
			count++;
			size_t nextPose = 0;
			getline(input, mystatoin);
			nextPose = mystatoin.find('|');
			for (auto workstation : workSP) {
				if (workstation->getItemName().compare (mystatoin.substr(0, nextPose++)) == 0) {
					for (auto workstationNext : workSP) {
						if (workstationNext->getItemName().compare(mystatoin.substr(nextPose, mystatoin.find('\n'))) == 0) {
							workstation->setNextStation(*workstationNext);
						}
					}
				}
			}
		}
	} while (input);
	input.close();
	for (auto workstation : workSP) {
		AssemblyLine.push_back(workstation);
	}
	//AssemblyLine = workSP;
	for (auto customer : filcus) {
		ToBeFilled.push_back(move(customer));
	}
	m_cntCustomerOrder = count;

}
bool LineManager::run(std::ostream& os) {
	bool runComplete = false;
	static size_t i = 0;
	os << i++;


	if (ToBeFilled.size() == 0)
		runComplete = true;
	return runComplete;
}
void LineManager::displayCompletedOrders(std::ostream& os) const {

}
void LineManager::displayStations() const {

}
void LineManager::displayStationsSorted() const {

}