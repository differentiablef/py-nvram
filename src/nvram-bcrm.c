#include <Python.h>

static PyObject *SpamError, *local_dict;

static PyObject *
spam_system(PyObject *self, PyObject * args)
{
	const char *command;
	int sts;

	if(!PyArg_ParseTuple(args, "s", &command))
		return NULL;

	sts = system(command);
	if ( sts < 0 ) {
		PyErr_SetString(SpamError, "System command failed");
		return NULL;
	}
	return PyLong_FromLong(sts);
}

PyMODINIT_FUNC
initspam(void)
{
	PyObject *m;
	static PyMethodDef SpamMethods[] = {
		{"system", spam_system, METH_VARARGS, "Execute a shell command."},
		{NULL, NULL, 0, NULL}
	};
	m = Py_InitModule("spam", SpamMethods);
	if ( m == NULL )
		return;

	SpamError = PyErr_NewException("spam.error", NULL, NULL);
	Py_INCREF(SpamError);
	PyModule_AddObject(m, "error", SpamError);
	
	local_dict = PyDict_New();
	Py_INCREF(local_dict);
	PyModule_AddObject(m, "words", local_dict);
}

int
main(int argc, char *argv[])
{
	Py_SetProgramName(argv[0]);
	Py_Initialize();
	initspam();
}
