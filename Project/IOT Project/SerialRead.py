import mysql.connector as mc
import serial
ids = []
keywords = ['busy','available','free']
presence = ['Class 404','Cabin','Library','class']
id_ = ""
present = ""
status = ""

def update(id_,present,status):
	try:
		cur.execute("UPDATE employee SET present_in = %s , status = %s WHERE tag_id = %s",(present,status,id_))
	except Exception:
		print("Unable to update Data")
	mydb.commit()
	print("Updated...")

def insert(id_,name,present,status):
	try:
		cur.execute("INSERT INTO employee (tag_id, name, present_in, status) VALUES (%s,%s,%s,%s)",(id_,name,present,status))
	except Exception:
		print("Unable to insert data")
	mydb.commit()
	print("Inserted...")

def delete(id_):
	try:
		cur.execute("DELETE FROM employee WHERE tag_id = %s",(id_))
	except Exception:
		print("Unable to delete record")
	mydb.commit()
	print("Deleted...")

def updateName(id_,name):
	cur.execute("UPDATE employee SET name = %s WHERE tag_id = %s",(name,id_))
	mydb.commit()
	print("Name Updated...")

def deleteName(name):
	cur.execute("DELETE FROM employee WHERE name = %s",(name))
	mydb.commit()
	print("Name Deleted...")

def selectAll():
	cur.execute("SELECT * FROM employee")
	idx = cur.fetchall()
	print("ID's fetched")
	for i in idx:
		ids.append(str(i[0]))
	print(ids)

try:
	mydb = mc.connect(host="localhost",user="Niranjan",passwd="123456",database="Niranjan")
except Exception:
	print("Unable to Connect to DataBase")
cur = mydb.cursor()
selectAll()
ser = serial.Serial('/dev/ttyACM2',baudrate=9600,timeout=1)

while(True):
	rx=""
	rx = ser.readline()
	if(len(rx)):
		print(str(rx)[:len(rx)-2])
		for i in ids:
			if(i in rx):
				id_ = i 
				for j in presence:
					if(j in rx):
						present = j
						for k in keywords:
							if(k in rx):
								status = k
								update(id_,present,status)