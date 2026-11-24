#pragma once
#include <string>

class Document
{
public:
    explicit Document(const std::string& titre);
    virtual ~Document() = default;

    const std::string& getTitre() const;

    virtual void afficher() const = 0;

protected:
    std::string titre_;
};