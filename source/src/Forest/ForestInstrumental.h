#ifndef RANGER_ForestInstrumental_H
#define RANGER_ForestInstrumental_H

#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include "globals.h"
#include "Forest.h"

#include <iostream>
#include <vector>
#include <unordered_map>

#include "globals.h"
#include "Forest.h"
#include "Tree.h"

class ForestInstrumental: public Forest {
public:
  ForestInstrumental(std::unordered_map<std::string, size_t> observables,
                     RelabelingStrategy* relabeling_strategy,
                     SplittingRule* splitting_rule,
                     PredictionStrategy* prediction_strategy);
  virtual ~ForestInstrumental();

private:
  void initInternal(std::string status_variable_name);
  void computePredictionErrorInternal();
  void writeOutputInternal();
  void writeConfusionFile();
  void writePredictionFile();

  void addSampleWeights(size_t test_sample_idx,
                        Tree* tree,
                        std::unordered_map<size_t, double> &weights_by_sampleID);
  void normalizeSampleWeights(std::unordered_map<size_t, double> &weights_by_sampleID);
  void predictInternal();

  DISALLOW_COPY_AND_ASSIGN(ForestInstrumental);
};


#endif //RANGER_ForestInstrumental_H
