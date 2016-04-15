/**
 * \file ClientDataHolder.hpp
 * \brief ClientDataHolder class definition
 */
#ifndef _CLIENTDATAHOLDER_
#define _CLIENTDATAHOLDER_

#include <iostream>
#include <vector>

using namespace std;

/**
 * \class ClientDataHolder
 * \brief Holds initialization data to send to arriving client 
 */
class ClientDataHolder {
	private:
		vector<string> filesToBeSent;
	public:
		/*!
		 * \brief No-arg constructor. 
		 * Equivalent to WorldSimulator(false, false)
		 **/
		ClientDataHolder();
		
		/*!
		 * \brief Getter for list filesToBeSent
		 **/
		vector<string> getFilesList();
		
		/*!
		 * \brief Adds the given file to the list filesToBeSent
		 **/
		void addFileToList(string newFile);
};

#endif
