
import qrcode


generate_img = qrcode.make("HI guys")

generate_img.save('MyQRCode.png')
