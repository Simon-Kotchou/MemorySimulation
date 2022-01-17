/**
 * This file contains implementations for methods in the PageTable class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "page_table/page_table.h"

using namespace std;


size_t PageTable::get_present_page_count() const {
	size_t present_pages = 0;

	for(int i = 0; i < rows.size(); i++){
		if(rows.at(i).present == true){
			present_pages++;
		}
	}
	return present_pages;	
}


size_t PageTable::get_oldest_page() const {
	size_t oldest_page_index = -1;
	size_t oldest_page = 1000000000;
	
	for(int i = 0; i < rows.size(); i++){
		if(rows.at(i).present == true && rows.at(i).loaded_at < oldest_page){
			oldest_page_index = i;
			oldest_page = rows.at(i).loaded_at;
		}
	}
	return oldest_page_index; 
}


size_t PageTable::get_least_recently_used_page() const {
	size_t least_recent_index = -1;
	size_t least_recent = 1000000000;

	for(int i = 0; i < rows.size(); i++){
		if(rows.at(i).present && rows.at(i).last_accessed_at < least_recent){
			least_recent_index = i;
			least_recent = rows.at(i).last_accessed_at;
		}
	}
	return least_recent_index;
}
