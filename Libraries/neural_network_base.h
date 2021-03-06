#ifndef NEURALNETWORK_NEURAL_NETWORK_BASE_H
#define NEURALNETWORK_NEURAL_NETWORK_BASE_H

#include "Base/synapse.h"

#include <map>
#include <random>
#include <vector>

/// @brief Defines the neural network architecture
/// @attention Currently, works only with a single hidden layer architecture
class NeuralNetworkBase {
public:
  /// @brief Defines the numbers of neurons in the input layer
  /// @param size Value representing how many neurons will the input layer have
  void SetNumberOfNeuronsInInputLayer(std::size_t size);

  /// @brief Defines the numbers of neurons in one hidden layer
  /// @param size Value representing how many neurons will the hidden layer have
  void SetNumberOfNeuronsInSingleHiddenLayer(std::size_t size);

  /// @brief Defines the numbers of neurons in the output layer
  /// @param size Value representing how many neurons will the output layer have
  void SetNumberOfNeuronsInOutputLayer(std::size_t size);

  /// @brief Creates the whole neural network with defined layers, synapses and
  /// values assigned to them.
  /// @param input_values Values assigned to the input layer neurons
  void CreateNetwork(const std::vector<Value> &input_values,
                     const std::vector<Value> &output_targets);

  /// @brief Gets the synapses
  /// @return Vector of filled synapses
  std::multimap<Id, Synapse> GetSynapses() const;

protected:
  /// @brief Creates the layers of the neural network based on the predefined
  /// network architecture size
  /// @param input_values Input values which will be assigned to the input layer
  /// neurons
  void CreateLayers(const std::vector<Value> &input_values,
                    const std::vector<Value> &output_targets);

  /// @brief Assign values to neurons in the input layer
  /// @param [in] input_values Input values which will be assigned to the input
  /// layer neurons
  void SetInputValues(const std::vector<Value> &input_values);

  /// @brief Assign target values to neurons in the output layer
  /// @param [in] target_values Target values which will be assigned to neurons
  /// in the output layer
  void SetTargetOutputValues(const std::vector<Value> &target_values);

  /// @brief Assign initial random values to the passed layer
  /// @param layer Layer to which the values will be assigned
  void CreateNeuronsInLayer(std::vector<Neuron> &layer);

  /// @brief Connects all layers of the defined neural network
  void ConnectNetwork();

  /// @brief Defines the parent-child relationship which is connected with a
  /// synapse. Each synapse has its own weight.
  /// @param parent Parent neuron
  /// @param child Child neuron
  void ConnectLayers(std::vector<Neuron> &parent, std::vector<Neuron> &child);

  // Helper functions
  inline double GenerateRandomValue();
  void AreLayersSizeAndCapacitySame();

  // Random generator
  std::random_device random_device_;
  std::default_random_engine generator_{random_device_()};
  std::uniform_real_distribution<double> distribution_{0.0, 1.0};

  // Data members
  std::multimap<Id, Synapse> synapses_{};
  std::vector<Neuron> input_layer_{};
  std::vector<Neuron> hidden_layer_{};
  std::vector<Neuron> output_layer_{};

  Id synapse_id_{0};
  Id neuron_id_{0};
};

#endif // NEURALNETWORK_NEURAL_NETWORK_BASE_H
