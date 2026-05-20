//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "AList.h"
#include "Node.h"
#include "FileList.h"

// --------------------------------
// -->    MODIFY This FILE    <----
// --------------------------------

FileList::FileList()
: pHead(nullptr),
NumNodes(0)
{
	// Hint you might need to rework this...
	// if you add data to FileList class
}

FileList::~FileList()
{
	// Hint you might need to rework this...
	Node *del = pHead;

	if (del != nullptr)
	{
		Node *temp = del;

		del = del->pNext;

		delete temp;
	}

	pHead = nullptr;
}


void FileList::WriteToFile(const char * const pFileName, AList *pAList)
{
	// Do your magic

	// Make sure you close the file after you fill it
	// Use fopen,fwrite,ftell,...,fclose

	// Hint: Open the file, write the nodes into the file 

	// Grads - You need to do the Load-In-Place technique
	//         You cannot have more than 2 new functions in this method
	    
	// Ungrads - You need to store the data and reconstruct the linked list
	//           You can use as many new/deletes as needed

	// Everyone - Fill in your destructor.

	// Quick sample code... remove this code and replace with your own

	FILE *pFileHandle = nullptr;

	assert(pFileName);
	errno_t status;

	int numNodes = pAList->GetNumNodes();
	size_t nodeSize = sizeof(Node) - (2 * sizeof(Node *));
	size_t buffer = size_t(numNodes * nodeSize);

	char *data = new char[buffer];

	Node *curr = pAList->GetHead();
	char *dataPtr = data;

	while (curr)
	{
		memcpy_s(dataPtr, nodeSize, reinterpret_cast<char *>(curr) + 2 * sizeof(Node *), nodeSize);
		dataPtr += nodeSize;

		curr = curr->pNext;
	}

	status = fopen_s(&pFileHandle, pFileName, "wb");
	assert(pFileHandle);
	assert(status == 0);

	fwrite(data, 1, buffer, pFileHandle);
	fclose(pFileHandle);
	delete data;


	/*status = fopen_s(&pFileHandle, pFileName, "wb");
	assert(pFileHandle);
	assert(status == 0);

	int quickSample = 0xAABBCCDD;

	size_t numBytesWritten = fwrite(&quickSample, 1, sizeof(int), pFileHandle);
	AZUL_UNUSED_VAR(numBytesWritten);
	assert(numBytesWritten == sizeof(int));

	fclose(pFileHandle);*/

}

FileList::FileList(const char * const pFileName, int numNodes)
{
	// Do your magic here:

	// Create the Linked List... You cannot use the original code
	// The input file, and numNodes is all you need to recreate the FileList
	
	// Hint: Open the file, read and create new nodes, 
	//       fill them with the data from the file

	// Grads - You need to do the Load-In-Place technique
	//         You cannot have more than 2 new functions in this method
	     
	// Ungrads - You need to store the data and reconstruct the linked list
	//           You can use as many new/deletes as needed

	// Everyone - Fill in your destructor.

	// Quick sample code... remove this code and replace with your own

	size_t nodeSize = sizeof(Node) - (2 * sizeof(Node *));
	size_t buffer = size_t(numNodes * nodeSize);

	FILE *pFileHandle;

	errno_t status;
	assert(pFileName);
	status = fopen_s(&pFileHandle, pFileName, "rb");
	assert(pFileHandle);
	assert(status == 0);
	
	char *data = new char[buffer];
	fread(data, 1, buffer, pFileHandle);
	fclose(pFileHandle);

	char *dataPtr = data;
	Node *newListHead = new Node[(uint32_t)numNodes];
	this->pHead = newListHead;
	this->NumNodes = numNodes;


	newListHead->pPrev = nullptr;
	newListHead->pNext = nullptr;
	Node *curr = newListHead;
	Node *prev = newListHead->pPrev;
	int i = 0;

	//Copy
	while (i < numNodes)
	{
		memcpy_s(&curr->x, nodeSize, dataPtr, nodeSize);

		//Linking and updating
		dataPtr += nodeSize;
		if (prev)
		{
			prev->pNext = curr;
		}
		curr->pPrev = prev;
		i++;
		prev = curr;
		curr = &newListHead[i]; 
	}

	delete[] data;

	//assert(data == 0xAABBCCDD);
}

// ---  End of File ---
