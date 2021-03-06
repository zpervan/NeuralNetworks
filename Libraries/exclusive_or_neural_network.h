#ifndef NEURALNETWORK_SIMPLE_NEURAL_NETWORK_H
#define NEURALNETWORK_SIMPLE_NEURAL_NETWORK_H

#include "Base/neural_network_data.h"
#include "activation_functions.h"
#include "neural_network_base.h"

using SynapseIterator = std::multimap<Id, Synapse>::iterator;

class ExclusiveOrNeuralNetwork : public NeuralNetworkBase {
public:
  /// @brief Define a neural network architecture with given layer sizes and
  /// input values.
  /// @param network Defines the size of the network layers
  /// @param input_values Values which will be assigned to the input layer
  /// neurons
  /// @todo: Consider making input_values and output_targets as a data
  /// member of NeuralNetworkArchitecture
  void
  DefineNeuralNetworkArchitecture(NeuralNetworkArchitecture network,
                                  const std::vector<Value> &input_values,
                                  const std::vector<Value> &output_targets);

  /// @todo Consider to make this a part of DefineNeuralNetworkArchitecture
  /// @brief Calculates the initial values for defined synapses.
  void CalculateInitialValues();

  /// @brief Trains the neural network. Basically, alternating between forward
  /// and backward propagation.
  void Train();

  /// @brief Prints the neural network data to the console
  void PrintNeuralNetworkData();

protected:
  double ApplyActivationFunction(double value);

  void CalculateNeuronValues(
      const std::pair<SynapseIterator, SynapseIterator> &found_synapses);

  void ApplyActivationFunctionOnNeuronsValue(
      const SynapseIterator &calculated_value);

  void PrintLayerData(const std::vector<Neuron> &layer) const;

  void
  SetActivationFunctionType(ActivationFunctionType activation_function_type);

  ActivationFunctionType activation_function_type_{
      ActivationFunctionType::UNKNOWN};
};

#endif // NEURALNETWORK_SIMPLE_NEURAL_NETWORK_H
