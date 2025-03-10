/* 
 * File:   Child.h
 * Author: Bastien Clément & Alain Hardy
 * 
 * Goal: Déclaration des enfants
 *
 * Les enfants surchargent la méthode validateState pour s'assurer qu'ils
 * ne sont pas laissés seuls avec le parent de sexe opposé.
 *
 * Created on 18.05.16.
 */

#ifndef LABO16_CHILD_H
#define LABO16_CHILD_H

#include "Person.h"
#include "FamilyMember.h"

/**
 * Un enfant
 */
class Child : public FamilyMember {
public:
	Child(const string& name);
	virtual bool canDrive() const;
};

/**
 * Un garçon
 */
class Boy : public Child {
public:
	Boy(const string& name);
	virtual void accept(class PersonVisitor& visitor) const;
	virtual void validateState(const class Container& container) const;
};

/**
 * Une fille
 */
class Girl : public Child {
public:
	Girl(const string& name);
	virtual void accept(class PersonVisitor& visitor) const;
	virtual void validateState(const class Container& container) const;
};

#endif //LABO16_CHILD_H
