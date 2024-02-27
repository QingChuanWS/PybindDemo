import pybind_demo as m


def test_module():
    assert m.__version__ == "0.0.1"
    assert m.add(1, 2) == 3
    assert m.subtract(1, 2) == -1

    p = m.Pet("demo")
    assert p.getName() == "demo"
    p.setName("Demo")
    assert p.getName() == "Demo"
    
    assert str(p) == "<example.Pet named 'Demo'>"
