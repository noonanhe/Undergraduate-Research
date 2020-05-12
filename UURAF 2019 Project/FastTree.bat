#!/bin/bash --login
#########Sbatch lines###########

#SBATCH --time=24:00:00
#SBATCH --ntasks=2
#SBATCH --cpus-per-task=2
#SBATCH --mem-per-cpu=50G
#SBATCH --job-name FastTree

########command lines############

srun ./FastTree -gtr -gamma -nt outfile_species_fasta.txt >fast_species_file
scontrol show job $SLURM_FAST_TREE