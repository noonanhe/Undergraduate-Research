# UURAF 2019 Project

### Poster
I have provided the pdf version of the poster that I presented at the Undergraduate University Research and Arts Forum. My poster
and presentation earned me a 1st place award at the forum.

### Concat_Fasta.cpp
I wrote this short C++ program to take in the raw mouse data and clean it. I was only interested in a certain subspecies in the data file. The first
time I created inference trees, they contained all specimens from my desired subspecies. I quickly realized that there were too many mice to make the 
tree readable/understandble on a poster. So I decided to choose about 2 or 3 mice from each subspecies to include in my analysis. Each mouse in the data file
had a 3 letter identifier. I used this identifier to extract the DNA sequences that I wanted. From there, the two write functions can be used to 
write the desired DNA sequences and identifiers in 2 different formats, phylip or fasta. Both are common formats used by phylogenetic inferencing software.
I needed the data in these formats so I could run it through RAxML and FastTree.

### Batch Files
These batch files demonstrate the 2 main jobs I had to submit to the HPCC (High Perfomance Computer Cluster) and how I did it.

##### raxml.bat
This runs tells RAxML (a tool for maximum-liklihood phylogenetic inference) to take the DNA sequences from `outfile_species_phylip.txt` and 
construct 20 phylogenetic inference trees under the Generalized Time Reversible model (GTRGAMMA), then using maximum liklihood, determine the 
best inference tree.

##### FastTree.bat
This batch file submits a jobs similar to the previous one, but this time uses a different phylogenetic inference algorithm (FastTree)
