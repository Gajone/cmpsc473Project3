#pragma once
#include "virtualMemoryManagerInterface.h"
#include <vector>

using namespace std;

class memoryManager :public virtualMemoryManagerInterface {
public:
	//memoryManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA) : policy(p), N(pS), numFrames(nF), virtualAddressSpaceSize(vA) {

	memoryManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA) : virtualMemoryManagerInterface(p, pS, nF, vA) {

		//Thomas Wenner 5/3/2017 stuff

		//calculate number of indexes in page table vector
		unsigned long long pageTableVectorlength = numFrames;

		//make struct for stuff and stuff
		struct pageTableAddress{
			unsigned long long address;		//virtual address stored at this page table address (phyiscal address is the index number)
			unsigned long long counter;		//used for LRU (evicts address with the lowest number once the page table is filled)
			bool inMemory=false;
		};

		//make Page Table Vector
		vector<pageTableAddress> myPageTable;
		myPageTable.reserve(pageTableVectorlength);		//set length of page table vector

		unsigned long long replacementIndex=0;		//for the FIFO implementation function
		unsigned long long myCounter = 0;
	}




	/** This is the method the test bench will drive in emulating memory
	management.
	* Your memory manager should return the physical address corresponding
	to the given virtual
	* address. This function must NOT return until any page swapping is
	completed, if necessary.
	* This function is to effect page swaps by calling the other key
	function (defined below)
	*/
	unsigned long long memoryAccess(unsigned long long address);
	/** This is the method your memory manager should call to swap pages.
	* This function has been instrumented by the TAs to report memory
	system performance.
	* @param frameNumber the physical frame to write to swap file (write
	is emulated)
	* @param pageNumber the (virtual) page number to read from swap file
	into the given frame
	*/
	void swap(unsigned int frameNumber, unsigned int pageNumber);


};