/**
 * \file ClientDataHolder.cpp
 * \brief Implementation of ClientDataHolder.hpp
 */
#include "ClientDataHolder.hpp"

ClientDataHolder::ClientDataHolder(){
	
}

vector<string> ClientDataHolder::getFilesList(){
	return this->filesToBeSent;
}

void ClientDataHolder::addFileToList(string newFile){
	this->filesToBeSent.push_back(newFile);
}
