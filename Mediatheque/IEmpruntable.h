#pragma once

class IEmpruntable
{
public:
    virtual ~IEmpruntable() = default;

    virtual bool emprunter() = 0;
    virtual bool retourner() = 0;
    virtual bool estDisponible() const = 0;
};