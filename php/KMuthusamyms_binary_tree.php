<?php
/**
 * This is a class for creating the binary nodes
 */
class BinaryNode { 

    public $data; 
    public $left; 
    public $right; 

    public function __construct(string $data = NULL) { 
      $this->data = $data; 
      $this->left = NULL; 
      $this->right = NULL; 
    } 

    /**
     * Adds child nodes
     */
    public function addChildren($left, $right) { 
      $this->left = $left;
      $this->right = $right;
    }

}

/**
 * Class for creating the binary tree
 */
class BinaryTree { 

    private $root = null;

    public function __construct() {
        $this->root = null;
    }

    /**
     * Method to check if the tree is empty
     */
    public function isEmpty() {
        return $this->root === null;
    }

    /**
     * Method to insert elements in to the binary tree
     */
    public function insert($data) {
        $node = new BinaryNode($data);
        if ($this->isEmpty()) { // this is the root node
            $this->root = $node;
            return true;
        } else {
            return $this->insertNode($node, $this->root);
        }
    }

    /**
     * Method to recursively add nodes to the binary tree
     */
    private function insertNode($node, $current) {
        $added = false;
        while($added === false) {
            if ($node->data < $current->data) {
                if($current->left === null) {
                    $current->addChildren($node, $current->right);
                    $added = $node;
                    break;
                } else {
                    $current = $current->left;
                    return $this->insertNode($node, $current);
                }
                
            }
            elseif ($node->data > $current->data) {
                if($current->right === null) {
                    $current->addChildren($current->left, $node);
                    $added = $node;
                    break;
                } else {
                    $current = $current->right;
                    return $this->insertNode($node, $current);
                    }
            } else {
                break;
            }
        }
        return $added;   
    }

    /**
     * Method to retrieve a node from the binary tree
     */
    public function retrieve($node) {
        if ($this->isEmpty()) { // this is the root node
            return false;
        }
            if ($node->data === $this->root->data) {             
              return $this->root;
            } else {
              $current = $this->root;
              return $this->retrieveNode($node, $current);        
            }
    }

    /**
     * Method to recursively add nodes to a binary tree
     */
    private function retrieveNode($node, $current) {
        $exists = false;
        while($exists === false) {
            if ($node->data < $current->data) {
              if ($current->left === null) {
                break;
                }
                elseif($node->data == $current->left->data) {
                  $exists = $current->left;
                  break;
                }
                 else {
                    $current = $current->left;
                    return $this->retrieveNode($node, $current);
                }
                
            }
            elseif ($node->data > $current->data) {
              if ($current->right === null) {
                break;
              }
              elseif($node->data == $current->right->data) {
                $exists = $current->right;
                break;
              } else {
                $current = $current->right;
                return $this->retrieveNode($node, $current);
                }
            }
        }
        return $exists;
    }

    /**
     * Method to convert the binary tree to an array and print it out
     */
    public function printTree() {

    }

    private function findParent($child, $current) {
        $parent = false;
        while ($parent === false) {
          if ($child->data < $current->data) {
            if ($child->data === $current->left->data) {
              $parent = $current;
              break;
            } else {
              return $this->findParent($child, $current->left);
              break;
            }
          }
          elseif ($child->data > $current->data) {
            if ($child->data === $current->right->data) {
              $parent = $current;
              break;
            } else {
              return $this->findParent($child, $current->right);
              break;
            }
          } else {
            break;
          }
        }
        return $parent;
      }
  
      
  
      /**
       * Method to remove an element from the binary tree
       */
      public function removeElement($elem) {
          if ($this->isEmpty()) {
              return false;
          }

          $node = $this->retrieve($elem);
          
          if (!$node) {
            return false;
          }
  
          //Case one remove the root
          if ($elem->data === $this->root->data) {
            // find the largest value in the left sub tree
            $current = $this->root->left;
            while($current->right != null) {
                $current = $current->right;
                continue;
            }
            // set this node to be the root
            $current->left = $this->root->left;
            $current->right = $this->root->right;

            $parent = $this->findParent($current, $this->root);
            $parent->right = $current->left;

            $this->root = $current;
            return true;
          }

          // case two we are removing a leaf node
          if ($node->left === null and $node->right === null) {
            $parent = $this->findParent($node, $this->root);
            if ($parent->left->data && $node->data === $parent->left->data) {
              $parent->left = null;
              return true;
            }
            elseif ($parent->right->data && $node->data === $parent->right->data) {
              $parent->right = null;
              return true;
  
            }
            return $parent;
          }
      }

    public function size() {

    }
}
