from Bio import AlignIO
import sys

"""
Calculates the gappiness of an alignment
:param aln: the alignment
:return: the gappiness of the alignment
"""
def Gappiness(aln):
    gap = list()
    for record in aln:
        gap.append(record.seq.count('-')/len(record.seq))
    return(sum(gap)/len(gap))

""" This program is called from a shell script where the MSA alignment is 
passed as the first argument and the true alignment as the second
"""
align_file = sys.argv[1]
trueAlign_file = sys.argv[2]

alignment = AlignIO.read(open(align_file), "fasta")
trueAlignment = AlignIO.read(open(trueAlign_file), "fasta")

print("Number of taxa: %i" %len(alignment))
print("Alignment length: %i" % alignment.get_alignment_length())
print("Alignment Gappiness:", Gappiness(alignment))
print("True Alignment length %i" % trueAlignment.get_alignment_length())
print("True Alignment Gappiness:", Gappiness(trueAlignment))
