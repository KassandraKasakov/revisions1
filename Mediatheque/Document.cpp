#include "Document.h"

Document::Document(const std::string& titre)
{
	titre_ = titre;
}

const std::string& Document::getTitre() const
{
	return titre_;
}
