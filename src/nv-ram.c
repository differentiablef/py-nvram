
#include <Python.h>

#include "common.h"
#include "nv-device.h"
#include "nv-ram.h"

#define MAX_PARAMS        20 

/* *******************************************************
 * NVRAM Method Function Implementations
 * ******************************************************/

LIB_LOCAL
PyObject *nvram_attach(PyObject *self, PyObject *args, PyObject *params)
{
    uintptr_t param_val[ MAX_PARAMS /* magic */ ];
    
    static char *kwlist[] = { "driver", "config", NULL };
    
    struct nvdev_obj *dev,
	**pdev = nvram_drivers;    

    char *pname,
	*err_string;
    
    PyObject *pconfig = NULL,
	*err_type = NULL;
    
    MARKER_MSG("parse");

    /* attempt to extract arguments and keywords (borrowed refs) */
    if( !PyArg_ParseTupleAndKeywords(
	    args, params, "s|O", kwlist, &pname, &pconfig) )
	return NULL;

    /* search for driver named pname  */
    for( ; (*pdev) != NULL; pdev++ ) {
	dev=*pdev;
	if( dev->name && (strcmp (pname, dev->name) == 0) )
	    break;
    }
    
    if( dev == NULL ) {
	/* if search unsuccessful, emit an error */
	
	err_type   = PyExc_KeyError;
	err_string = "unknown device driver";
	goto error;
    }
    
    if( pconfig && dev->config ) {
	/* if both pconfig and dev->config are provided, then
	       process pconfig and setup device parameters */
	
	int cur = 0;
	
        struct nvdev_param *param;
	PyObject *val;
	
	/* process the list of config parameters from dev->config, */
	/*    setting the value to those specified in pconfig      */

	param = dev->config;;

    process_param:
	
	/* get value associated with key param->id from pconfig  */
	val = PyDict_GetItemString (pconfig, param->id);

	if( val == NULL ) {
	    /* pconfig has no value associated with param->id, is
	       this a problem ? */
	    
	    if( param->required ) {
		/* yes, param->id is required, so emit an error.  */
	    
		err_type   = PyExc_KeyError;
		err_string =
		    "'config' (pos 2) missing required entry";
		goto error;
	    }

	    /* no, skip to next param */
	    param_val[ cur ] = UNDEFINED;
	    goto next_param;
	}

	switch( param->type ) {
	    
	case PARAM_INTEGER:
	    if( ! PyLong_CheckExact( val ) ) {
		err_type = PyExc_TypeError;
		err_string =
		    "improper key value type (config) (integer expected)";
		goto error;
	    }

	    param_val[cur] = (uintptr_t) PyLong_AsVoidPtr( val );
	    goto next_param;
	    
	case PARAM_BOOL:
	    if( ! PyBool_Check( val ) ) {
		err_type = PyExc_TypeError;
		err_string =
		    "improper key value type (config) (bool expected)";
		goto error;
	    }
	    
	    if( val == Py_True )
		param_val[ cur ] = true;
	    else if(val == Py_False )
		param_val[ cur ] = false;

	    goto next_param;
	    
	case PARAM_STRING:
	    /* MARKER_MSG("string"); */
	    
	    param_val[ cur ] = 0;
	    goto next_param;
	    
	default:
	    err_type = PyExc_RuntimeWarning;
	    err_string =
		"Aborted: Potential Memory Corruption Or"	\
		" Shitty Driver";
	    goto error;

	}

    next_param:
	cur++;
	if( (++param)->id != NULL )
	    goto process_param;

	
    } else if( dev->config_required && (pconfig == NULL) ) {
	/* our device required 'config' to have a value */
	/*   since it's NULL, emit an error             */
	err_type   = PyExc_TypeError;
	err_string = "named driver requires 'config' (pos 2) argument";	    
	goto error;
	
    }

    MARKER_MSG("attach device");
    if( (dev->attach) && (dev->attach(dev, param_val) < 0) ) {
	/* failed to attach to device, so emit an error */
	
	err_type   = PyExc_RuntimeError;
	err_string = "failed to attach device";
	goto error;
	
    }

    Py_INCREF(pconfig);
    PyModule_AddObject(self, "magic", pconfig);
    
    Py_RETURN_NONE;

error:
    PyErr_SetString (err_type, err_string);
    
    return NULL;

}

LIB_LOCAL
PyObject *nvram_detach(PyObject *self)
{
    /* error handling */
    PyObject *err_type;
    char *err_string;
    
    Py_RETURN_NONE;

error:
    PyErr_SetString (err_type, err_string);
    
    return NULL;

}

LIB_LOCAL
PyObject *nvram_get(PyObject *self, PyObject *args)
{
    /* error handling */
    PyObject *err_type;
    char *err_string;
    
    /* parameter values */
    char *pname;

    if( !PyArg_ParseTuple(args, "s", &pname) )
	return NULL;

    DEBUG(pname, "s");
    
    

    Py_RETURN_NONE;

error:
    PyErr_SetString (err_type, err_string);
    
    return NULL;

}

LIB_LOCAL
PyObject *nvram_set(PyObject *self, PyObject *args)
{
    /* error handling */
    PyObject *err_type;
    char *err_string;

    /* parameter values */
    char *pname, *pvalue;

    if( !PyArg_ParseTuple(args,"ss",&pname, &pvalue) )
	return NULL;

    DEBUG(pname, "s");
    DEBUG(pvalue, "s");
    
    Py_RETURN_NONE;
    
error:
    PyErr_SetString (err_type, err_string);
    
    return NULL;

}

LIB_LOCAL
PyObject *nvram_unset(PyObject *self, PyObject *args)
{
    /* error handling */
    PyObject *err_type;
    char *err_string;

    /* parameter values */
    char *pname;

    if( !PyArg_ParseTuple(args, "s", &pname) )
	return NULL;

    DEBUG(pname, "s");
    
    Py_RETURN_NONE;

error:
    PyErr_SetString (err_type, err_string);
    
    return NULL;

}

LIB_LOCAL
PyObject *nvram_commit(PyObject *self)
{
    /* error handling */
    PyObject *err_type;
    char *err_string;
    
    Py_RETURN_NONE;

error:
    PyErr_SetString (err_type, err_string);
    
    return NULL;

}

LIB_LOCAL
PyObject *nvram_lock(PyObject *self)
{
    /* error handling */
    PyObject *err_type;
    char *err_string;
    
    Py_RETURN_NONE;

error:
    PyErr_SetString (err_type, err_string);
    
    return NULL;

}

LIB_LOCAL
PyObject *nvram_unlock(PyObject *self)
{
    /* error handling */
    PyObject *err_type;
    char *err_string;
    
    Py_RETURN_NONE;

error:
    PyErr_SetString (err_type, err_string);
    
    return NULL;

}

LIB_LOCAL
PyObject *nvram_stats(PyObject *self)
{
    /* error handling */
    PyObject *err_type;
    char *err_string;
    
    Py_RETURN_NONE;
    
error:
    PyErr_SetString (err_type, err_string);
    
    return NULL;
}


//adwaita
// airline-papercolor

// airline-simple
// misterioso

// tango-dark
// powerlineish

// solarized-alternate-gui
// tango

// airline-wombat
// wombat

// airline-durant
// airline-hybirdline
// airline-molokai



/*  LocalWords:  pconfig
 */
