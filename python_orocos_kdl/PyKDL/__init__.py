try:
    from .PyKDL import *
except ImportError:
    # Fallback if the module is built in development mode
    import sys
    import os
    sys.path.insert(0, os.path.dirname(__file__))
    from PyKDL import *

# Export the KDL version from the module
__version__ = PyKDL.__version__
