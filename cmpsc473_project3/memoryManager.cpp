#include "memoryManager.h"

using namespace std;

unsigned long long memoryManager::memoryAccess(unsigned long long address) {
	if (p == FIFO) {
		if (fifoPhysicalMemory.size==numframes) {

		}
		else {
			fifoPhysicalMemory.push_back(address);
		}
	}
	else if (p == LRU) {


	}
	else
		cout << "error" << endl;
}

void memoryManager::swap(unsigned int frameNumber, unsigned int pageNumber) {

}