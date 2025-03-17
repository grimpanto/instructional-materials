// @copyright 2019 Günter Kolousek

#pragma once

#include <string>

namespace numbercheck {

  enum class State {
      Eps, S, G, V, E, L, K, B, W, F
  };

  class FloatingPointChecker {
    public:
      bool check(std::string e) {
          State z{State::S};
          bool completed{true};
          for (auto c : e) {
              z = delta(z, c);
              if (z == State::Eps) {
                  completed = false;
                  break;
              }
          }
          if (completed)
              if (z == State::G || z == State::L || z == State::B || z == State::F)
                  return true;
          return false;
      }
    private:
      State delta(State z, char c) {
          switch (z) {
            case State::S:
              switch (c) {
                case '+': [[fallthrough]];
                case '-':
                  z = State::V;
                  break;
                case '0': [[fallthrough]];
                case '1': [[fallthrough]];
                case '2': [[fallthrough]];
                case '3': [[fallthrough]];
                case '4': [[fallthrough]];
                case '5': [[fallthrough]];
                case '6': [[fallthrough]];
                case '7': [[fallthrough]];
                case '8': [[fallthrough]];
                case '9':
                  z = State::G;
                  break;
                case '.':
                  z = State::K;
                  break;
                default:
                  z = State::Eps;
              }
              break;
            case State::V:
              switch (c) {
                case '0': [[fallthrough]];
                case '1': [[fallthrough]];
                case '2': [[fallthrough]];
                case '3': [[fallthrough]];
                case '4': [[fallthrough]];
                case '5': [[fallthrough]];
                case '6': [[fallthrough]];
                case '7': [[fallthrough]];
                case '8': [[fallthrough]];
                case '9':
                  z = State::G;
                  break;
                case '.':
                  z = State::K;
                  break;
                default:
                  z = State::Eps;
              }
              break;
            case State::G:
              switch (c) {
                case '0': [[fallthrough]];
                case '1': [[fallthrough]];
                case '2': [[fallthrough]];
                case '3': [[fallthrough]];
                case '4': [[fallthrough]];
                case '5': [[fallthrough]];
                case '6': [[fallthrough]];
                case '7': [[fallthrough]];
                case '8': [[fallthrough]];
                case '9':
                  z = State::G;
                  break;
                case '.':
                  z = State::L;
                  break;
                case 'e':
                  z = State::E;
                  break;
                default:
                  z = State::Eps;
              }
              break;
            case State::L:
              switch (c) {
                case '0': [[fallthrough]];
                case '1': [[fallthrough]];
                case '2': [[fallthrough]];
                case '3': [[fallthrough]];
                case '4': [[fallthrough]];
                case '5': [[fallthrough]];
                case '6': [[fallthrough]];
                case '7': [[fallthrough]];
                case '8': [[fallthrough]];
                case '9':
                  z = State::B;
                  break;
                case 'e':
                  z = State::E;
                  break;
                default:
                  z = State::Eps;
              }
              break;
            case State::K:
              switch (c) {
                case '0': [[fallthrough]];
                case '1': [[fallthrough]];
                case '2': [[fallthrough]];
                case '3': [[fallthrough]];
                case '4': [[fallthrough]];
                case '5': [[fallthrough]];
                case '6': [[fallthrough]];
                case '7': [[fallthrough]];
                case '8': [[fallthrough]];
                case '9':
                  z = State::B;
                  break;
                default:
                  z = State::Eps;
              }
              break;
            case State::B:
              switch (c) {
                case '0': [[fallthrough]];
                case '1': [[fallthrough]];
                case '2': [[fallthrough]];
                case '3': [[fallthrough]];
                case '4': [[fallthrough]];
                case '5': [[fallthrough]];
                case '6': [[fallthrough]];
                case '7': [[fallthrough]];
                case '8': [[fallthrough]];
                case '9':
                  z = State::B;
                  break;
                case 'e':
                  z = State::E;
                  break;
                default:
                  z = State::Eps;
              }
              break;
            case State::E:
              switch (c) {
                case '0': [[fallthrough]];
                case '1': [[fallthrough]];
                case '2': [[fallthrough]];
                case '3': [[fallthrough]];
                case '4': [[fallthrough]];
                case '5': [[fallthrough]];
                case '6': [[fallthrough]];
                case '7': [[fallthrough]];
                case '8': [[fallthrough]];
                case '9':
                  z = State::F;
                  break;
                case '+': [[fallthrough]];
                case '-':
                  z = State::W;
                  break;
                default:
                  z = State::Eps;
              }
              break;
            case State::F:
              switch (c) {
                case '0': [[fallthrough]];
                case '1': [[fallthrough]];
                case '2': [[fallthrough]];
                case '3': [[fallthrough]];
                case '4': [[fallthrough]];
                case '5': [[fallthrough]];
                case '6': [[fallthrough]];
                case '7': [[fallthrough]];
                case '8': [[fallthrough]];
                case '9':
                  z = State::F;
                  break;
                default:
                  z = State::Eps;
              }
              break;
            case State::W:
              switch (c) {
                case '0': [[fallthrough]];
                case '1': [[fallthrough]];
                case '2': [[fallthrough]];
                case '3': [[fallthrough]];
                case '4': [[fallthrough]];
                case '5': [[fallthrough]];
                case '6': [[fallthrough]];
                case '7': [[fallthrough]];
                case '8': [[fallthrough]];
                case '9':
                  z = State::F;
                  break;
                default:
                  z = State::Eps;
              }
              break;
            case State::Eps:
              break;
          }
          return z;
      }
  };

}
