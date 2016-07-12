import nvram

ret = nvram.attach(
    driver="dummy",
    config=dict( path="/not/a/path",
                 local=True,
                 offset=-13452465,
                 doYouLift=True ) )

row = nvram.attach(
    "dummy",
    {
        'path': "/not/a/path",
        'local': True,
        'offset': -4,
        'doYouLift': False
        
    })


