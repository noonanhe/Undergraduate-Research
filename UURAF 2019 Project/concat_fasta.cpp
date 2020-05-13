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


map <string, string> mice= {{"ASS",""},{"AMQ",""},{"ASA",""},{"AKS",""},{"ARI",""},
    {"ALK",""},{"AWQ",""},{"ADY",""},{"AEM",""},{"AMG",""},{"ANA",""},{"AOI",""},
    {"AIG",""},{"ACS",""},{"ADQ",""},{"ALW",""},{"AMO",""},{"ALQ",""},{"AJS",""},
    {"AZC",""},{"ACQ",""},{"BAG",""},{"AKI",""},{"APO",""},{"AQC",""},{"AWK",""},
    {"AXE",""},{"ABY",""}}; 

map <string, string> species= {{"ADG",""},{"ASS",""},{"ARU",""},{"AXQ",""},{"AIE",""},{"AWI",""},{"AGK",""}
   ,{"AIK",""},{"AGM",""},{"AFS",""},{"AZQ",""},{"AOQ",""},{"AIO",""},{"AHU",""},{"AMQ",""},{"ASA",""},{"AKS",""},
   {"AGA",""},{"AXC",""},{"AQY",""},{"AFM",""},{"ALO",""},{"AAQ",""},{"APA",""},{"AIL",""},{"AJE",""},{"AQS",""},
   {"ASQ",""},{"ATK",""}};

/** Determines whether a string is an identifier or not
* \param str Line from a file being read in
* \returns bool indicating whether the line contains the identifier/key
**/
bool is_key(string& str){
    if (str.size()==11){
        return true;
    }
    return false;
}

/**Cleans up the line containing an identifier to just the identifier
* \param str Line containing identifier
* \returns cleaned identifier
**/
string make_key(string& str){
    string key;
    for (auto i=str.size()-3; i<str.size(); ++i){
        key+=str[i];
    }//grabs last 3 chars of string
    return key;
}//make_key

/** Prints the elements in a map
* \param out The out stream to use
* \param m The map to print out
* \returns the outstream being printed to
**/
ostream& print_map(ostream& out, map<string,string> &m){
    for (auto element: m){
        out << element.first << ":" <<element.second<<endl;
    }//for each string in the vector
    return out;
}//print_map

/** Reads in the file contain the mouse DNA data
* \param name The name of the file containing the data
**/
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
}//read_file function

/// Writes the desired data to a file in phylip format
void write_file_phylip(){
    ofstream out_file;
    out_file.open("outfile_species_phylip.txt");
    map <string, string>::iterator itr= species.find("ASS");
    out_file << species.size() <<" "<< (*itr).second.size()<<endl;
     for (auto element: species){
        out_file << element.first << " " <<element.second<<endl;
    }//for each string in the vector
}//writes to an output file

/// Writes the desired data to a file in fasta format
void write_file_fasta(){
    ofstream out_file;
    out_file.open("outfile_species_fasta.txt");
    for (auto element:species){
        out_file << ">"<<element.first <<endl;
        out_file << element.second <<endl;
    }//for each string in the vector
}//write to an output file but in fasta format

int main(){
    /** The DNA sequences of each mouse were separated into 20 different files, because their DNA was sequences in 20 different chunks.
    I chose to read in each of these 20 files separately, concatanating them within this formatting script. **/
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
    read_file("phased.fasta13");
    read_file("phased.fasta14");
    read_file("phased.fasta15");
    read_file("phased.fasta16");
    read_file("phased.fasta17");
    read_file("phased.fasta18");
    read_file("phased.fasta19");
    read_file("phased.fastaX");
    for (auto element: species){
        cout << element.first <<" "<<element.second.size()<<endl;
    }
    write_file_phylip();
    write_file_fasta();
}//end of main
