import tkinter
from datetime import datetime
import numpy
from astropy.time import Time
from astropy.coordinates import solar_system_ephemeris, EarthLocation
from astropy.coordinates import get_body

class geodeticLocation():
    def __init__(self):
        self.root = tkinter.Tk()
        self.root.geometry('718x360')
        self.root.resizable(False, False)
        self.root.title('Geodetic Locator')
        self.root.config(bg='black')
        self.root.wm_attributes('-toolwindow', True)
        
        # render world map
        bg = tkinter.PhotoImage(file='Res/worldmap.png')

        self.map = tkinter.Label(self.root, image=bg, border=0, relief="solid", width=718, height=360)
        self.map.place(x=0, y=0)

        # dropdown menu for selecting planets
        selection = tkinter.StringVar()

        options = [
            'Mercury',
            'Venus',
            'Mars',
            'Jupiter',
            'Saturn',
            'Uranus',
            'Neptune'
        ]

        selection.set('Select')

        self.menu = tkinter.OptionMenu(self.root, selection, *options, command=self.plot)
        self.menu.config(height=1, width=10, bg='black', fg='white', border=0, activebackground='black', activeforeground='white', indicatoron=0)
        self.menu['menu'].configure(relief=tkinter.FLAT, border=0, activeborderwidth=5, activeforeground='white', activebackground='black', selectcolor='#1abc9c')
        self.menu.place(x=20, y=0)

        # marker
        image = tkinter.PhotoImage(file='Res/mark.png')

        self.marker = tkinter.Label(self.root, image=image, borderwidth=0, relief="solid", height=7, width=7)
        self.label = tkinter.Label(self.root, borderwidth=0, text='bruh')

        self.root.mainloop()


    def plot(self, selection):
        # set time to current time and location to null island
        t = Time(datetime.now().strftime('%Y-%m-%d %H:%M'))
        loc = EarthLocation.from_geodetic(0, 0)

        # get selected body
        with solar_system_ephemeris.set('builtin'):
            body = get_body(selection.lower(), t, loc)

        # get geodetic coodinates of the body and convert to pixel location on world map image
        if (numpy.float32(body.dec) > 0):
            lat = 180 - numpy.float32(body.dec) * 2
            label_y = 10
            direction_y = 'N' 
        else:
            lat = 180 + abs(numpy.float32(body.dec)) * 2
            label_y = -20
            direction_y = 'S' 

        if (numpy.float32(body.ra) > 180):
            lon = (numpy.float32(body.ra) - 180) * 1.9944
            label_x = 12
            lon_value = 360 - (numpy.float32(body.ra))
            direction_x = 'W' 
        else:
            lon = (numpy.float32(body.ra) + 180) * 1.9944
            label_x = -30
            lon_value = numpy.float32(body.ra)
            direction_x = 'E'

        # place marker on the coordinates
        self.marker.place(x=lon, y=lat)
        self.label['text'] = str(round(numpy.float32(body.dec), 2)) + '°' + direction_y + '\n' + str(round(lon_value, 2)) + '°' + direction_x
        self.label.place(x=lon + label_x, y=lat + label_y)


app = geodeticLocation()
