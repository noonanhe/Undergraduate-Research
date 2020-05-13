# Bipartition Analysis Project



### Alignment_Analysis.py
This is a simple script used to deterimine certain measures about the true alignment (raw data), and the multiple sequences alignment, 
including the number of taxa (how many samples), alignment length (length of DNA sequence, and gappiness (the proportion of indels (insertion/deletion)
events in the sequence)

### Branch Frequency Results
This powerpoint is a rough representation of some of my initial results. Each bar in the bar graphs represents a unique bipartition. For example,
out of all the resampled inference trees of Replicate 2, there were 47 unique bipartitions. The height of each bar represents how many times that 
bipartition appeared among resamples (i.e Branch Support). The bars colored green are bipartitions that appear in the inference tree,
the red colored bars are bipartitions that appear in the model (true) tree (this analysis was done using simulated data, therefore a true tree
could be known), bars colored green and red are bipartitions that appeared in the model and inference tree. In this particular case, each tree 
contains 7 bipartitions. So a really good inference tree would contain 7 bipartitions with high branch support and ideally, all 7 branches
would also be correct (i.e they would be bipartions in the model tree). These initial results indicated that there were bipartions in the model
tree that were not present in any of the resampled trees, thus no inference tree could be completely correct. Additionally, there were bipartitions
with high levels of support that didn't appear in the inference tree. Some of these did appear in the model tree and others were just flukes.

### Bipartition Analysis Results
The first slide in this powerpoint is probably the most interesting/meaningful in this result set. The four graphs displayed on this slide visualize
the aggreagate results over all 20 replicates (each replicate had 100 resamples) under a single condition. 
The blue histogram takes all the unique bipartitions from the first analysis and places them into buckets based on their level of branch support. A bipartition with a branch support
value of 80, means that that bipartition appeared in 80 of the resampled trees. This first histogram looks how we would expect it to. It makes sense
that the majority of bipartitions have low branch support values, there are only 7 bipartitions in the model tree so in a perfect world, there would
be 7 bipartitions with branch support values of 100, and the remaining bipartitions would have low branch support values.
The red histogram, representing the bipartitions in the model tree is quite interesting. Again, in a perfect world, all 7 of these bipartitions
would have support values of 100, but we can immediately see that this is not the case. In fact, about 30% of the model trees bipartitons have
support values between 0 and 20. This can be explained by no event branches, meaning that there have been no mutations in them. No event branches
pose a huge problem for phylogenetic inference alogrithm which rely on mutations to reach their conclusions.
The green histogram represents the bipartitions found in the inference trees. We would hope that the majority of the bipartitions in our inferences
would have high support values, meaning that our guesses have good statistical support. This histogram suggests that about 43% of the bipartitions
in our inferences trees have high levels of support.


###calBranchFrequency.py
In this program I utilize a few methods written by another lab member in our lab and build upon them to create dictionaries containing the unique bipartitions
and the number of times they occur in the total resamples, the model tree, and the inference tree. I also iterate through these dictionaires to put the bipartitons
into buckets for the historgrams I used for result visualization.

### branchFrequency.sh
I decided to include this small shell script to kind of represent the pipeline procedure I used in my research project. Most of these shell scritps
consist of providing a result directory (where the results from RAWR analysis (another project done by our lab) were stored). Each condition 
had 20 replicates. This script would iterate over the 20 replicates, calling the calBranchFrequency program, passing the replicate trees, model tree,
and inference tree files in as parameters and then writing the results to a file called `branchFrequencies`.
