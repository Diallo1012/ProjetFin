import psycopg2
import serial
import time
from datetime import datetime

# Paramètres de connexion à la base de données PostgreSQL
host = 'localhost'
port = '5432'
database = 'capteur'
user = 'postgres'
password = 'Diallo'
Date = datetime.now()
# Configuration de la communication série (à adapter selon votre configuration)
serial_port = 'COM15'
baud_rate = 9600

# Connexion à la base de données PostgreSQL
try:
    conn = psycopg2.connect(
        host=host,
        port=port,
        database=database,
        user=user,
        password=password
    )
    print("Connecté à la base de données")
except psycopg2.Error as e:
    print("Échec de la connexion à la base de données:", e)
    exit()

cursor = conn.cursor()
# Ouverture de la connexion série
try:
    ser = serial.Serial(serial_port, baud_rate)
    print("Connexion série établie")
except serial.SerialException as e:
    print("Échec de la connexion série:", e)
    exit()

while True:
    # Lecture des données depuis le microcontrôleur via la communication série
    line = ser.readline().decode().strip()
    line2 = ser.readline().decode().strip()
    # data = line.split(',')
    val1 = float(line)
    val2 = float(line2)

    # Insérer les données dans la base de données
    query1 = "INSERT INTO carbone (donnee_carb, date) VALUES (%s, %s)"
    query2 = "INSERT INTO lumiere (donnee_lum, date) VALUES (%s, %s)"
    
    cursor.execute(query1, (val1, Date))
    cursor.execute(query2, (val2, Date))
    conn.commit()
    print("Données insérées dans la base de données")
    # except psycopg2.Error as e:
    #     print("Erreur lors de l'insertion des données:", e)
    # try:
    #     conn.commit()
    #     print("Données insérées dans la base de données")
    # except psycopg2.Error as e:
    #     print("Erreur lors de l'insertion des données:", e)

# Fermeture de la connexion
    cursor.close()
    conn.close()
    time.sleep(3) # temps d ettente a la reesecution du programme