//
// Created by abodi on 06/04/2020.
//

#ifndef ANCESTOR_TREE_A_FAMILYTREE_HPP
#define ANCESTOR_TREE_A_FAMILYTREE_HPP
#include <string>
#include <iostream>
using namespace std;
namespace family {
    class Node{
        friend class Tree;
    private:
        Node* m_father;
        Node* m_mother;
        std::string m_name;
        std::size_t m_len;
        bool m_isfather;
        bool m_isme=false;
    public:
        Node( std::string name):m_name(name), m_father(NULL), m_mother(NULL), m_len(0)
        {

        }

        Node(const Node& n): m_name(n.m_name)
        {
            if(n.m_mother != NULL)
                m_mother = new Node(*n.m_mother);
            if(n.m_father != NULL)
                m_father = new Node(*n.m_father);
        }
        /*getters*/
        Node* get_father(){ return this->m_father;}
        Node* get_mother(){ return this->m_mother;}
        string get_name(){ return this->m_name;}
        std::size_t get_len(){ return this->m_len;}
        bool isme(){return this->m_isme;}
        bool isfather(){ return this->m_isfather;}
        /*setters*/
        void set_father(string str)
        {
            if(m_father != NULL)
                delete m_father;
            this->m_father=new Node(str);
        }
        void set_mother(string str)
        {
            if(m_mother != NULL)
                delete m_mother;
            this->m_mother=new Node(str);
        }
        void set_name(string str){ this->m_name = str;}
        void set_len(std::size_t i){ this->m_len=i;}
        void set_bool_isme(bool x){this->m_isme=x;}
        void set_bool_isfather(bool x){this->m_isfather=x;}
        /*Destructor*/
        ~Node()
        {
            if(m_mother != NULL)
                delete m_mother;
            if(m_father != NULL)
                delete m_father;

        }

    };
    class Tree {
        Node *root; /*youngest*/

        Tree(const Tree& toCopy): root(new Node(*toCopy.root)) {}

        void display_rec(Node *);

        Node *relation_rec(Node *, const string);

        Node *find_rec(Node *, int, bool);

        void remove_rec(Node *, const string);

        void remove_rec_pntrToPntr(Node *&, const string);

        void addMother_rec(Node *n, const string son, const string mother, size_t len)/*O(n)*/
        {
            if (n == NULL) {
                return;
            }
            if (n->get_name() == son) /* same string*/
            {
                n->set_mother(mother);
                n->get_mother()->set_len(len + 1);
                return;
            }

            addMother_rec(n->get_father(), son, mother, len + 1);
            addMother_rec(n->get_mother(), son, mother, len + 1);
        }

        void addFather_rec(Node *n, const string son, const string father, size_t len)/*O(n)*/
        {
            if (n == NULL) {
                return;
            }
            if (n->get_name() == son) /* same string*/
            {
                n->set_father(father);
                n->get_father()->set_len(len + 1);
                n->get_father()->set_bool_isfather(true);
                return;
            }

            addFather_rec(n->get_father(), son, father, len + 1);
            addFather_rec(n->get_mother(), son, father, len + 1);
        }

    public:
        Tree() { this->root = NULL; }

        Tree(const std::string str) {
            this->root = new Node(str);
            this->root->set_len(0);
            this->root->set_bool_isme(true);
        }

        Node *Get_root() { return this->root; }

        Tree& addFather(const string son, const string father);

        Tree& addMother(const string son, const string mother);

        void display();

        string relation(const string str);

        string find(const string str);

        void remove(const string target);

        ~Tree()
        {
            if(this->root!=NULL)
            delete this->root;
        }
    };

}

#endif //ANCESTOR_TREE_A_FAMILYTREE_HPP
