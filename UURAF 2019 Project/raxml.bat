#!/bin/bash --login
###### SBATCH Lines for Resource Request ##########

#SBATCH --job-name raxml
#SBATCH --ntasks=2
#SBATCH --cpus-per-task=2
#SBATCH --mem-per-cpu=50G
#SBATCH --time=24:00:00

####### Command Lines to Run ############

srun ./raxmlHPC -m GTRGAMMA -p 12345 -s outfile_species_phylip.txt -# 20 -n micespecies
scontrol show job $SLURM_raxml