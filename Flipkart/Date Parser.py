#Date parser

from datetime import datetime
from dateutil import parser

str = "1st Jan 1992"

date_object = parser.parse(str)


date_object = datetime.strftime(date_object, '%Y-%m-%d')

print(date_object)