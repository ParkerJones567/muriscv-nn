
if [ -f ../Wiki/aww_corePerf.txt ]; then
    rm -rf ../Wiki/aww_corePerf.txt
fi

if [ -f ../Wiki/vww_corePerf.txt ]; then
    rm -rf ../Wiki/vww_corePerf.txt
fi

if [ -f ../Wiki/toy_corePerf.txt ]; then
    rm -rf ../Wiki/toy_corePerf.txt
fi

if [ -f ../Wiki/ic_corePerf.txt ]; then
    rm -rf ../Wiki/ic_corePerf.txt
fi

if [ -f ../Wiki/perfEstimatorResults.csv ]; then
    rm -rf ../Wiki/perfEstimatorResults.csv
fi

../Sim/PEXT_Estimator/Scripts/test_muRISCV_nn.sh -b aww  >> ../Wiki/aww_corePerf.txt
../Sim/PEXT_Estimator/Scripts/test_muRISCV_nn.sh -b vww  >> ../Wiki/vww_corePerf.txt
../Sim/PEXT_Estimator/Scripts/test_muRISCV_nn.sh -b toy  >> ../Wiki/toy_corePerf.txt
../Sim/PEXT_Estimator/Scripts/test_muRISCV_nn.sh -b ic  >> ../Wiki/ic_corePerf.txt

../Sim/PEXT_Estimator/Scripts/test_muRISCV_nn.sh -b aww -p >> ../Wiki/aww_corePerf.txt
../Sim/PEXT_Estimator/Scripts/test_muRISCV_nn.sh -b vww -p  >> ../Wiki/vww_corePerf.txt
../Sim/PEXT_Estimator/Scripts/test_muRISCV_nn.sh -b toy -p  >> ../Wiki/toy_corePerf.txt
../Sim/PEXT_Estimator/Scripts/test_muRISCV_nn.sh -b ic -p  >> ../Wiki/ic_corePerf.txt

cd ../Wiki
python3 create_wiki_perfEstimator.py

      
      
