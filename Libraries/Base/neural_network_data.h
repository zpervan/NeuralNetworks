#ifndef NEURALNETWORK_NEURAL_NETWORK_ARCHITECTURE_DATA_H
#define NEURALNETWORK_NEURAL_NETWORK_ARCHITECTURE_DATA_H

#include "../activation_functions.h"

#include <cstdint>

using Id = std::uint64_t;
using Value = double;
using Weight = double;

/// @TODO: Add multiple levels of hidden layer
struct NeuralNetworkArchitecture {
  std::size_t input_layer_size;
  std::size_t single_hidden_layer_size;
  std::size_t output_layer_layer_size;
  ActivationFunctionType activation_function_type;
};

/// @brief Defines one neuron in the network
struct Neuron {
  const Id id{0};
  Value value{0.0};
  Value activation_func_result{0.0};
  Value output_target{0.0};
};

#endif // NEURALNETWORK_NEURAL_NETWORK_ARCHITECTURE_DATA_H
