#pragma once
#include "virtualMemoryManagerInterface.h"
#include <vector>

using namespace std;

class memoryManager :public virtualMemoryManagerInterface {
public:
	virtualMemoryManagerInterface(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA) : policy(p), N(pS), numFrames(nF), virtualAddressSpaceSize(vA) {
		assert(virtualAddressSpaceSize > N);
		assert(pow(2, virtualAddressSpaceSize) > numFrames * pow(2, N));
		if (p==FIFO) {
			//allocate vector for stuff
			vector<unsigned long long> fifoPhysicalMemory;
			fifoPhysicalMemory.reserve(numframes);


			vector<unsigned long long> fifoVirtualMemory;

		}
		else if (p==LRU) {
			//not sure what data structure to use yet

		}
		
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
	unsigned long long memoryAccess(unsigned long long address) override;
	/** This is the method your memory manager should call to swap pages.
	* This function has been instrumented by the TAs to report memory
	system performance.
	* @param frameNumber the physical frame to write to swap file (write
	is emulated)
	* @param pageNumber the (virtual) page number to read from swap file
	into the given frame
	*/
	void swap(unsigned int frameNumber, unsigned int pageNumber) override;


};