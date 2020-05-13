#!/bin/bash

#parameters
currDir=`pwd`
resultDir="/mnt/home/noonanhe/Documents/uuraf2020/RAWR/sim-results/10taxa/condition1"


for ((i=1;i<=20;i++))
do
	cd ${resultDir}/replicate$i
	treesFile=rawr.trees
	modelFile=model.tree
	inferFile=infer.tree
	python $currDir/calBranchFrequency.py ${treesFile} ${modelFile} ${inferFile} > branchFrequencies
done
cd $currDiir
