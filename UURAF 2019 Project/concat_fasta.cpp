#include <fstream>
using std::ifstream; using std::ofstream; using std::basic_ifstream;
using std::basic_ofstream;
#include <map>
using std::map; using std::end; using std::begin;
#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout; using std::endl; using std::ostream;
using std::flush;
#include <sstream>
using std::ostringstream;
#include <iterator>
/*need to open file
maybe i should use a map with key as their ID tag and 
find the tags i need and then add that block to the corresponding file
*/

map <string, string> mice= {{"ASS",""},{"AMQ",""},{"ASA",""},{"AKS",""},{"ARI",""},
    {"ALK",""},{"AWQ",""},{"ADY",""},{"AEM",""},{"AMG",""},{"ANA",""},{"AOI",""},
    {"AIG",""},{"ACS",""},{"ADQ",""},{"ALW",""},{"AMO",""},{"ALQ",""},{"AJS",""},
    {"AZC",""},{"ACQ",""},{"BAG",""},{"AKI",""},{"APO",""},{"AQC",""},{"AWK",""},
    {"AXE",""},{"ABY",""}}; 
//ifstream in_file("test_fasta.txt");
map <string, string> species= {{"ADG",""},{"ASS",""},{"ARU",""},{"AXQ",""},{"AIE",""},{"AWI",""},{"AGK",""}
   ,{"AIK",""},{"AGM",""},{"AFS",""},{"AZQ",""},{"AOQ",""},{"AIO",""},{"AHU",""},{"AMQ",""},{"ASA",""},{"AKS",""},
   {"AGA",""},{"AXC",""},{"AQY",""},{"AFM",""},{"ALO",""},{"AAQ",""},{"APA",""},{"AIL",""},{"AJE",""},{"AQS",""},
   {"ASQ",""},{"ATK",""}};
string test= "AAAAAAAAAABFG";
string test2= "ACTGACTGATG";

bool is_key(string& str){
    if (str.size()==11){
        return true;
    }//
    return false;
}//checks to see if line is an identifier

string make_key(string& str){
    string key;
    for (auto i=str.size()-3; i<str.size(); ++i){
        key+=str[i];
    }//grabs last 3 chars of string
    return key;
}//make_key

ostream& print_map(ostream& out, map<string,string> &m){
    for (auto element: m){
        out << element.first << ":" <<element.second<<endl;
    }//for each string in the vector
    return out;
}//print_map

void read_file(string name){
    string str="";
    string key;
    ifstream in_file(name);
    string sequence;
    map<string, string>::iterator itr;
    while(getline(in_file, str)){
        if (str.length()==0){
            if (species.find(key)!=species.end()){
                itr=species.find(key);
                (*itr).second+=sequence;
            }//if a key is in the map
            /*else{
                itr= (mice.insert({key,""})).first;
            }*/
            /*(*itr).second+=sequence;
            key="";
            sequence.clear();*/
            key="";
            sequence.clear();
        }//if its a line break
        else {
            if (is_key(str)){
                key=make_key(str);
            }//if its an identifier line
            else{
                sequence+=str.substr(0, str.size()-1);
            }//if its a sequence line
        }//if its not a line break
    }//while there is still lines in the file
    /*if (mice.find(key)!=mice.end()){
        itr=mice.find(key);
    }
    else {
        itr= (mice.insert({key,""})).first;
    }
        sequence+=str.substr(str.size()-1);
        (*itr).second+=sequence;*/
}//read_file function

void write_file_phylip(){
    ofstream out_file;
    out_file.open("outfile_species_phylip.txt");
    map <string, string>::iterator itr= species.find("ASS");
    out_file << species.size() <<" "<< (*itr).second.size()<<endl;
     for (auto element: species){
        out_file << element.first << " " <<element.second<<endl;
    }//for each string in the vector
}//writes to an output file

void write_file_fasta(){
    ofstream out_file;
    out_file.open("outfile_species_fasta.txt");
    for (auto element:species){
        out_file << ">"<<element.first <<endl;
        out_file << element.second <<endl;
    }//for each string in the vector
}//write to an output file but in fasta format

int main(){
    read_file("phased.fasta");
    read_file("phased.fasta2");
    read_file("phased.fasta3");
    read_file("phased.fasta4");
    read_file("phased.fasta5");
    read_file("phased.fasta6");
    read_file("phased.fasta7");
    read_file("phased.fasta8");
    read_file("phased.fasta9");
    read_file("phased.fasta10");
    read_file("phased.fasta11");
    read_file("phased.fasta12");
    read_file("phased.fasta13");read_file("phased.fasta14");
    read_file("phased.fasta15");read_file("phased.fasta16");
    read_file("phased.fasta17");
    read_file("phased.fasta18");
    read_file("phased.fasta19");
    read_file("phased.fastaX");
    //print_map(cout, mice);
    for (auto element: species){
        cout << element.first <<" "<<element.second.size()<<endl;
    }
    write_file_phylip();
    write_file_fasta();
}//end of main