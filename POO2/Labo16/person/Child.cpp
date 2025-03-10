/* 
 * File:   Child.cpp
 * Author: Bastien Clément & Alain Hardy
 * 
 * Goal: Implémentation des enfants
 *
 * Ce fichier défini une classe "privée" ChildVisitor utilisée à
 * la fois par le garçon et la fille. En effet, la logique est la
 * même, et seul la vérification finale est différente.
 *
 * Created on 18.05.16.
 */


#include "Child.h"
#include "PersonVisitor.h"
#include "../Container.h"
#include "../ActionException.h"

Child::Child(const string& name) : FamilyMember(name) {}

bool Child::canDrive() const {
	return false;
}

class ChildVisitor : public PersonVisitor {
public:
	bool father = false;
	bool mother = false;

	virtual void visit(const Father&) { father = true; };
	virtual void visit(const Mother&) { mother = true; };
};

//
// Boy
//

Boy::Boy(const string& name) : Child(name) {}

void Boy::accept(PersonVisitor& visitor) const {
	visitor.visit(*this);
}

void Boy::validateState(const struct Container& container) const {
	ChildVisitor visitor;
	container.visit(visitor);
	if (visitor.mother && !visitor.father) {
		throw ActionException("Un garcon ne peut pas se trouver seul avec sa mere si son pere n'est pas present");
	}
}

//
// Girl
//

Girl::Girl(const string& name) : Child(name) {}

void Girl::accept(PersonVisitor& visitor) const {
	visitor.visit(*this);
}

void Girl::validateState(const struct Container& container) const {
	ChildVisitor visitor;
	container.visit(visitor);
	if (visitor.father && !visitor.mother) {
		throw ActionException("Une fille ne peut pas se trouver seule avec son pere si sa mere n'est pas presente");
	}
}
