#ifndef QPANDA_EXCEPTION_H
#define QPANDA_EXCEPTION_H

#include <exception>
#include <string>
using namespace std;

/*
|-QPandaException
|---qalloc_fail
|---calloc_fail
<<<<<<< HEAD
|---factory_init_error
|---duplicate_free

=======
|---duplicate_free

|---factory_exception
|------factory_init_error
|------factory_get_instance_fail

>>>>>>> c081d7d6d4a9f182e66b5a2e1e764f4bf35f0c19
|---load_exception
|------qubit_not_allocated
|------cbit_not_allocated

|---classical_system_exception
|------operator_specifier_error
|------content_specifier_error
|------eval_error
|------invalid_cbit_ptr
|------invalid_cmem

|---qubit_pool_exception
|------invalid_qubit_ptr
|------invalid_pool
*/

#define getssErrMsg(ssERRMSG,ERRMSG) \
                    ssERRMSG << __FILE__ <<" " <<__LINE__ << " " \
                             << __FUNCTION__ << ERRMSG

class QPandaException : public exception
{
    string errmsg;
    bool isFree;
    public:
    QPandaException()
    : exception()
    {
        errmsg = "Unknown error";
        isFree = false;
    }
    QPandaException(const char* str, bool isfree)
    : exception() {
        errmsg = str;
        isFree = isfree;
    }

    QPandaException(string str,bool isfree)
    : exception() {
        errmsg = str;
        isFree = isfree;
    }

    virtual const char* what()
    {
        return errmsg.c_str();
    }	
};

class qalloc_fail : public QPandaException
{
    public:
    qalloc_fail() : QPandaException(
        "qalloc fail",
        false
        ) {}
};




class calloc_fail : public QPandaException
{
    public:
    calloc_fail() : QPandaException(
        "calloc fail",
        false
        ) {}
};

class factory_exception : public QPandaException
{
    public:
    factory_exception() : QPandaException(
        "Unknown factory exception",
        false
        ){}
    factory_exception(string errmsg,bool isfree)
    : QPandaException(
        errmsg,
        isfree
        )
    {}
};

class factory_init_error : public factory_exception
{
    public:
    factory_init_error(string cls) : factory_exception(
        cls+" initialization error",
        false
        ) {}
};

class factory_get_instance_fail :public factory_exception
{
    public:
    factory_get_instance_fail(string cls) :factory_exception(
        cls+ " get a nullptr",
        false
        )
    {}
};

class classical_system_exception : public QPandaException
{
    public:
    classical_system_exception()
    :QPandaException(
        "Unknown Classical System Exception",
        false)
    {}
    classical_system_exception(string err, bool isfree) 
    : QPandaException(err,isfree)
    {};
};

class operator_specifier_error : public classical_system_exception
{
    public:
    operator_specifier_error()
    : classical_system_exception(
        "Operator not existed",
        false)
    {}
};

class content_specifier_error : public classical_system_exception
{
    public:
    content_specifier_error()
    : classical_system_exception(
        "contentSpecifier invalid",
        false)
    {}
};

class eval_error : public classical_system_exception
{
    public:
    eval_error()
    : classical_system_exception(
        "Evaluation of expression has failed",
        false)
    {}
};

class duplicate_free : public QPandaException
{
    public:
    duplicate_free(string cls)
    : QPandaException(
        cls+" duplicate free occurred",
        false
        )
    {}
};

class invalid_cbit_ptr : public classical_system_exception
{
    public:
    invalid_cbit_ptr()
    : classical_system_exception(
        "Invalid CBit Ptr",
        false
        )
    {}
};

class qubit_pool_exception : public QPandaException
{
    public:
    qubit_pool_exception()
    :QPandaException(
        "Unknown Qubit Pool Exception",
        false)
    {}
    qubit_pool_exception(string errmsg, bool isFree)
    : QPandaException(errmsg, isFree)
    {}
};

class invalid_qubit_ptr : public qubit_pool_exception
{
    public:
    invalid_qubit_ptr() 
    :qubit_pool_exception(
        "Invalid Qubit Ptr",
        false
        )
    {}
};

class invalid_pool : public qubit_pool_exception
{
    public:
    invalid_pool()
    :qubit_pool_exception(
        "invalid pool",
        false
        )
    {}
};

class invalid_cmem : public classical_system_exception
{
    public:
    invalid_cmem()
    :classical_system_exception(
        "invalid cmem",
        false
        )
    {}
};

class load_exception : public QPandaException
{
    public:
    load_exception(string errmsg, bool isFree)
    : QPandaException(errmsg, isFree)
    {}
    load_exception()
    : QPandaException(
        "unknown loader error",
        false)
    {}
};

class qubit_not_allocated : public load_exception
{
    public:
    qubit_not_allocated()
    :load_exception(
        "Qubit is Used Without Allocated",
        false
        )
    {}
};

class cbit_not_allocated : public load_exception
{
    public:
    cbit_not_allocated()
    :load_exception(
        "CBit is Used Without Allocated",
        false
        )
    {}
};

class circuit_not_found_exception: public QPandaException
{
public:
    circuit_not_found_exception(string errmsg, bool isFree)
        : QPandaException(errmsg, isFree)
    {}
    circuit_not_found_exception()
        : QPandaException(
            "unknown not found error",
            false)
    {}
};


class param_error_exception : public QPandaException
{
public:
    param_error_exception(string errmsg, bool isFree)
        : QPandaException(errmsg, isFree)
    {}
    param_error_exception()
        : QPandaException(
            "unknown param error",
            false)
    {}
};
class metadate_error_exception : public QPandaException
{
public:
    metadate_error_exception(string errmsg, bool isFree)
        : QPandaException(errmsg, isFree)
    {}
    metadate_error_exception()
        : QPandaException(
            "unknown param error",
            false)
    {}
};

#endif


