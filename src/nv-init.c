
#include "common.h"

/* *******************************************************
 * NVRAM Method Function Implementations
 * ******************************************************/

static PyObject *nvram_attach(PyObject *self, PyObject *nv_dev);
static PyObject *nvram_detach(PyObject *self);
static PyObject *nvram_get(PyObject *self, PyObject *name);
static PyObject *nvram_set(PyObject *self, PyObject *name, PyObject *val);
static PyObject *nvram_commit(PyObject *self);
static PyObject *nvram_lock(PyObject *self);
static PyObject *nvram_unlock(PyObject *self);
static PyObject *nvram_stats(PyObject *self);

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
        
  { "lock", nvram_lock, METH_NOARGS,
        "wait for a read/write lock on the nv-device"  },
        
  { "unlock", nvram_unlock, METH_NOARGS,
        "release a lock held on the nv-device"         },
        
  { "stats", nvram_stats, METH_NOARGS,
        "return a dict-obj with stats on nv-device"    },
                
  { NULL, NULL, 0,  NULL                               }
};

/* *******************************************************
 * NVRAM Module Initialization Routine
 * *******************************************************/
 
PyMODINIT_FUNC initnvram(void)
{
  PyObject *m;
  
  m = Py_InitModule3("nvram", NVRAM_Methods,
		     "Interface to system nvram device(s)");
		     
  if (m == NULL)
    return;
  
  /* SpamError = PyErr_NewException("spam.error", NULL, NULL); */
  /* Py_INCREF(SpamError); */
  /* PyModule_AddObject(m, "error", SpamError); */
  
  /* local_dict = PyDict_New(); */
  /* Py_INCREF(local_dict); */
  /* PyModule_AddObject(m, "words", local_dict); */
}



