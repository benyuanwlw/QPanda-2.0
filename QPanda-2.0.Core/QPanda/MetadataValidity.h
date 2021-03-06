/*
Copyright (c) 2017-2018 Origin Quantum Computing. All Right Reserved.
Licensed under the Apache License 2.0

GraphDijkstra.h
Author: Wangjing
Created in 2018-8-31

Classes for get the shortes path of graph

*/
#ifndef METADATAVALIDITYFUNCTIONVECTOR_H
#define METADATAVALIDITYFUNCTIONVECTOR_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <functional>


using namespace std;

enum SingleGateTransferType
{
    SINGLE_GATE_INVALID = -1,
    ARBITRARY_ROTATION,
    DOUBLE_CONTINUOUS,
    SINGLE_CONTINUOUS_DISCRETE,
    DOUBLE_DISCRETE
};

enum DoubleGateTransferType
{
    DOUBLE_GATE_INVALID = -1,
    DOUBLE_BIT_GATE
};

/*
Judge if the metadata's type is arbitrary rotation
param:
    gates: the gates is judged
    valid_gates: output the valid gates  
return:
    Return the style of metadata validity

Note:
*/
int arbitraryRotationMetadataValidity(vector<string>&gates, vector<string>&valid_gates);

/*
Judge if the metadata's type is double continuous
param:
    gates: the gates is judged
    valid_gates: output the valid gates
return:
    Return the style of metadata validity

Note:
*/
int doubleContinuousMetadataValidity(vector<string>&gates, vector<string>&valid_gates);

/*
Judge if the metadata's type is single continuous and discrete
param:
    gates: the gates is judged
    valid_gates: output the valid gates
return:
    Return the style of metadata validity

Note:
*/
int singleContinuousAndDiscreteMetadataValidity(vector<string>&gates, vector<string>&valid_gates);

/*
Judge if the metadata's type is double discrete
param:
    gates: the gates is judged
    valid_gates: output the valid gates
return:
    Return the style of metadata validity

Note:
*/
int doubleDiscreteMetadataValidity(vector<string>&gates, vector<string>&valid_gates);

/*
Judge double gate type
param:
    gates: the gates is judged
    valid_gates: output the valid gates
return:
    Return the style of metadata validity

Note:
*/
int doubleGateMetadataValidity(vector<string>&gates, vector<string>&valid_gates);

/*
add all functions of metadata validity
*/
typedef  function<int(vector<string>&, vector<string>&)> MetadataValidity_cb;
class MetadataValidity
{
public:
    void push_back(MetadataValidity_cb func);
    MetadataValidity_cb operator[](int i);
    size_t size();

    virtual ~MetadataValidity();

private:
    vector<MetadataValidity_cb> m_metadata_validity_functions;
};


/*
Get single gate metadata Validator type
*/
class SingleGateTypeValidator
{
public:
    SingleGateTypeValidator();
    static int GateType(vector<string>&gates, vector<string>&valid_gates);
    virtual ~SingleGateTypeValidator();

    MetadataValidity m_metadata_validity_functions;
private:

};


/*
Get double gate metadata Validator type
*/
class DoubleGateTypeValidator
{
public:
    DoubleGateTypeValidator();
    static int GateType(vector<string>&gates, vector<string>&valid_gates);
    virtual ~DoubleGateTypeValidator();

    MetadataValidity m_metadata_validity_functions;
private:

};


#endif // METADATAVALIDITYFUNCTIONVECTOR_H
