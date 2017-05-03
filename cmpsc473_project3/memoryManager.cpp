#include "memoryManager.h"

using namespace std;

unsigned long long memoryManager::memoryAccess(unsigned long long address) {

	//the return address
	unsigned long long myReturnAddress;
	//seperate incoming address into "pageOffset", the page offset, and "virtualPageNum", the "value" to look for in the indexes of the Page table vector
	unsigned long long pageOffset = (address<<(64-N))>>(64-N);	//get offset within page
	unsigned long long virtualPageNum = address>>N;				//get virtualPageNum

	bool stable = false;			//Page Table array is not filled yet

	if (p == FIFO) {
		//replacementIndex is a variable here
		
		//check all indexes of myPageTable for the virtualPageNum
		int i;
		for (i = 0; i < PageTableVectorlength; i++) {
			if (myPageTable[i].address == virtualPageNum && myPageTable[i].inMemory) {
				stable = true;
				myReturnAddress = (myPageTable[i].address<<N)+pageOffset;
				return myReturnAddress;
			}
			if (!stable) {
				myPageTable[replacementIndex].address = virtualPageNum;
				myPageTable[replacementIndex].inMemory = true;

				unsigned long long preReplacementIndex = replacementIndex;
				replacementIndex = (replacementIndex + 1) % pageTableVectorLength;
				swap(1,1);
				myReturnAddress = (preReplacementIndex<<N)+pageOffset;
				return myReturnAddress;
			}

		}
	}
	else if (p == LRU) {
		//check all indexes of myPageTable for the virtualPageNum
		int i;
		for (i = 0; i < PageTableVectorlength; i++) {
			if (myPageTable[i].address == virtualPageNum && myPageTable[i].inMemory) {
				stable = true;
				myReturnAddress = (myPageTable[i].address << N) + pageOffset;
				myPageTable[i].counter = myCounter;
				myCounter++;							//increment counter
				return myReturnAddress;
			}
			if (!stable) {
				//find replacement index
				int j;
				unsigned long long tempCount = 0;
				for (j=0;j < PageTableVectorlength;j++) {
					if (myPageTable[j].count <= tempCount)
						replacementIndex = j;
				}
				//we now have the replacement index
				//////

				myPageTable[replacementIndex].address = virtualPageNum;
				myPageTable[replacementIndex].inMemory = true;
				myPageTable[replacementIndex].count = myCounter;
				myCounter++;
				swap(1, 1);
				myReturnAddress = (ReplacementIndex << N) + pageOffset;
				return myReturnAddress;
			}

		}

	}
	else
		cout << "error" << endl;


	//to call swap, just do "swap(1,1); and do the swapping stuff in your own virtual memory implementation"
}

void memoryManager::swap(unsigned int frameNumber, unsigned int pageNumber) {

}