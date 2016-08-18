#ifndef RANGER_TREEQUANTILE_H
#define RANGER_TREEQUANTILE_H

#include "TreeRegression.h"
#include "TreeClassification.h"

class TreeQuantile : public TreeRegression {
public:
  TreeQuantile(std::vector<double> *quantiles);

  TreeQuantile(std::vector<std::vector<size_t>> &child_nodeIDs, std::vector<size_t> &split_varIDs,
               std::vector<double> &split_values, std::vector<bool> *is_ordered_variable,
               std::vector<double> *quantiles,
               std::vector<std::vector<size_t>> sampleIDs);

  bool splitNodeInternal(size_t nodeID, std::vector<size_t>& possible_split_varIDs);
  std::vector<size_t> get_neighboring_samples(size_t sampleID);

private:
  std::vector<uint>* relabelResponses(std::vector<double>* responses);
  TreeClassification* createClassificationTree(std::vector<size_t>& nodeSampleIDs,
                                               std::vector<uint>* relabeledResponses);

  void appendToFileInternal(std::ofstream& file);

  std::vector<double>* quantiles;
  std::uniform_int_distribution<uint> udist;

  DISALLOW_COPY_AND_ASSIGN(TreeQuantile);
};
#endif //RANGER_TREEQUANTILE_H