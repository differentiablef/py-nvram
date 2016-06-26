
#include "common.h"
#include "nv-device.h"

/* *******************************************************
 * NVRAM Method Function Implementations
 * ******************************************************/

static PyObject *nvram_attach(PyObject *self, PyObject *nvdev)
{
  Py_RETURN_NONE;
}

static PyObject *nvram_detach(PyObject *self)
{
  Py_RETURN_NONE;
}

static PyObject *nvram_get(PyObject *self, PyObject *name)
{
  Py_RETURN_NONE;
}

static PyObject *nvram_set(PyObject *self, PyObject *name, PyObject *val)
{
  Py_RETURN_NONE;
}

static PyObject *nvram_commit(PyObject *self)
{
  Py_RETURN_NONE;
}

static PyObject *nvram_lock(PyObject *self)
{
  Py_RETURN_NONE;
}

static PyObject *nvram_unlock(PyObject *self)
{
  Py_RETURN_NONE;
}

static PyObject *nvram_stats(PyObject *self)
{
  Py_RETURN_NONE;
}

/* *******************************************************
 * NVRAM Method Def 
 * ******************************************************/

static PyMethodDef NVRAM_Methods[] = 
{
  { "attach", nvram_attach, METH_VARARGS,
        "attach/connect module to specified nv-device" },
  
  { "detach", nvram_detach, METH_NOARGS,
        "detach/disconnect module from nv-device"      },
        
  { "get", nvram_get, METH_VARARGS, 
        "get specified cell value from nv-device"      },
        
  { "set", nvram_set, METH_VARARGS,
        "set specified cell of nv-device to value"     },
  { "unset", nvram_set, METH_VARARGS,
        "set specified cell of nv-device to value"     },        
  { "commit", nvram_commit, METH_NOARGS,
        "push any pending changes to the nv-device"    },
  /*      
  { "lock", nvram_lock, METH_NOARGS,
        "wait for a read/write lock on the nv-device"  },
        
  { "unlock", nvram_unlock, METH_NOARGS,
        "release a lock held on the nv-device"         },
  */    
  
  { "stats", nvram_stats, METH_NOARGS,
        "return a dict-obj with stats on nv-device"    },
                
  { NULL, NULL, 0,  NULL                               }
};

/* *******************************************************
 * NVRAM Module Def and Initialization Routine
 * *******************************************************/

static struct PyModuleDef NVRAM_Def = {
  PyModuleDef_HEAD_INIT,
  "nvram", NULL,
  -1,
  NVRAM_Methods
};

PyMODINIT_FUNC PyInit_nvram(void)
{
  PyObject *mod;
  
  mod = PyModule_Create( &NVRAM_Def );
		     
  if (mod == NULL)
    return NULL;
  
  /* SpamError = PyErr_NewException("spam.error", NULL, NULL); */
  /* Py_INCREF(SpamError); */
  /* PyModule_AddObject(m, "error", SpamError); */
  
  /* local_dict = PyDict_New(); */
  /* Py_INCREF(local_dict); */
  /* PyModule_AddObject(m, "words", local_dict); */

  
  return mod;
}



