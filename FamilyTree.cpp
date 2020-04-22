//
// Created by abodi on 08/04/2020.
//

#include <cstring>
#include "FamilyTree.hpp"

family::Tree& family::Tree::addMother(const string son, const string mother)
{
    family::Tree::addMother_rec(this->root,son,mother,this->root->get_len());
    return *this;
}

family::Tree& family::Tree::addFather(const string son, const string father)
{
    family::Tree::addFather_rec(this->root,son,father,this->root->get_len());
    return *this;
}
void family::Tree::display_rec(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<this->relation(root->get_name())<<": "<<root->get_name()<<endl;
    display_rec(root->get_father());
    display_rec(root->get_mother());
}
void family::Tree::display()
{
    display_rec(this->root);
}
family::Node* family::Tree::find_rec(Node* n, int length, bool isfather)
{
    if(n==NULL) return NULL;
    if(n->get_len()==length-1)
    {
        if(isfather)
        {
            if(n->get_father()!=NULL)
            {
                return n->get_father();
            }
            return NULL;
        }
        /* if(!father)~~mother*/
        if(n->get_mother()!=NULL)
        {
            return n->get_mother();
        }
        return NULL;
    }
    Node* n1=find_rec(n->get_father(),length,isfather);
    Node* n2=find_rec(n->get_mother(),length,isfather);
    if(n1==NULL) return n2;
    return n1;

}
string family::Tree::find(const string str) {
if(str=="me") return this->root->get_name();
if(str=="father")return this->root->get_father()->get_name();
if(str=="mother")return this->root->get_mother()->get_name();
/* no for each one in level >=2 applies with the rule
 * length= #of('-') in string + 2 */
    int counter=0;
    int index=0;
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i]=='-'){
            counter++;
            index=i;
        }
    }
    /*counter equals # of '-' in str !*/
    int len=2+counter;
    bool father=false;
    for (int j = index; j <str.length(); ++j) {
        if(str[j]=='f')
        {
            father=true;
            break;
        }
    }
    return find_rec(this->root,len,father)->get_name();

}

family::Node* family::Tree::relation_rec(Node* n,const string target)
{
    if(n==NULL)
    {
        return NULL;
    }
    if(n->get_name()==target)
    {
        return n;
    }
    Node* i=relation_rec(n->get_father(),target);
    Node* j= relation_rec(n->get_mother(),target);
    if(i==NULL) return j;
    return i;
}

string family::Tree::relation(const string str) {
    string ans;
        if (this->root == NULL) {
            return "TREE IS EMPTY ~!";
        }
    else {
            Node* n=relation_rec(this->root,str);
            if(n==NULL) return "Unrelated";
            if(n->get_len()==0) return "me";
            if(n->get_len()==1)
            {
                if(n->isfather()) return "father";
                return "mother";
            }
            else
                {
                    for (int i = 1; i < n->get_len()-1; ++i) {
                          ans+="great-";
                    }
                    if(n->isfather()) ans+="grandfather";
                    else ans+="grandmother";
                    return ans;
            }
        }
}
/*
void family::Tree::remove_rec(Node* n,const string str){
 if(n==NULL) return;
 if(n->get_name()==str) {
     delete n;
     return;
 }
 remove_rec(n->get_father(),str);
 remove_rec(n->get_mother(),str);

}*/

void family::Tree::remove_rec(Node* n,const string str){
    if(n->get_father() == NULL && n->get_mother()==NULL)
        return;
    if(n->get_father()->get_name() == str)
    {
        delete n->get_father();
        n->m_father = NULL;
    }
    if(n->get_mother()->get_name() == str)
    {
        delete n->get_mother();
        n->m_mother = NULL;
    }
    if(n->get_father() != NULL)
        remove_rec(n->get_father(),str);
    if(n->get_mother() != NULL)
        remove_rec(n->get_mother(),str);
}


void family::Tree::remove(const string target) {
    /*if(this->root->get_name() == target)
    {
        delete this->root;
        this->root = NULL;
        return;
    }
    remove_rec(this->root,target);*/
    remove_rec_pntrToPntr(this->root, target);
}

void family::Tree::remove_rec_pntrToPntr(family::Node* & n, const string str)
{
    if(n==NULL) return;
    if(n->get_name()==str) {
        delete n;
        n = NULL;

        return;
    }
    remove_rec_pntrToPntr(n->m_father,str);
    remove_rec_pntrToPntr(n->m_mother,str);

}


