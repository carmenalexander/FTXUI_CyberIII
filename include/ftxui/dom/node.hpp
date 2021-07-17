#ifndef FTXUI_DOM_NODE_HPP
#define FTXUI_DOM_NODE_HPP

#include <memory>  // for shared_ptr
#include <vector>  // for vector

#include "ftxui/dom/requirement.hpp"  // for Requirement
#include "ftxui/screen/box.hpp"       // for Box
#include "ftxui/screen/screen.hpp"

namespace ftxui {

class Node;
using Element = std::shared_ptr<Node>;
using Elements = std::vector<Element>;

class Node {
 public:
  Node();
  Node(Elements children);
  virtual ~Node();

  // Step 1: Compute layout requirement. Tell parent what dimensions this
  //         element wants to be.
  //         Propagated from Children to Parents.
  virtual void ComputeRequirement();
  Requirement requirement() { return requirement_; }

  // Step 2: Assign this element its final dimensions.
  //         Propagated from Parents to Children.
  virtual void SetBox(Box box);

  // Step 3: Draw this element.
  virtual void Render(Screen& screen);

 protected:
  std::vector<Element> children_;
  Requirement requirement_;
  Box box_;
};

void Render(Screen& screen, const Element& node);
void Render(Screen& screen, Node* node);

}  // namespace ftxui

#endif /* end of include guard: FTXUI_DOM_NODE_HPP */

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
