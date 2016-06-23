#include <Python.h>

PyMODINIT_FUNC
initnvram(void)
{
  PyObject *m;

  static PyMethodDef NVRAM_Methods[] = {
    {NULL, NULL, 0, NULL}
  };
  
  m = Py_InitModule("nvram", NVRAM_Methods);
  if ( m == NULL )
    return;
  
  /* SpamError = PyErr_NewException("spam.error", NULL, NULL); */
  /* Py_INCREF(SpamError); */
  /* PyModule_AddObject(m, "error", SpamError); */
  
  /* local_dict = PyDict_New(); */
  /* Py_INCREF(local_dict); */
  /* PyModule_AddObject(m, "words", local_dict); */
}
