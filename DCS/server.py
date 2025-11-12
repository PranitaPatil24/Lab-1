# from flask import Flask, request, jsonify

# app = Flask(__name__)

# @app.route('/operation', methods=['GET'])
# def perform_operation():
#     number = request.args.get('number', type=int)
#     operation = request.args.get('operation', default='square', type=str)

#     if number is None:
#         return jsonify({'error': 'Please provide a number parameter!'}), 400

#     if operation == 'square':
#         result = number ** 2
#     elif operation == 'cube':
#         result = number ** 3
#     elif operation == 'double':
#         result = number * 2
#     else:
#         return jsonify({'error': 'Invalid operation! Use square, cube, or double.'}), 400

#     return jsonify({
#         'number': number,
#         'operation': operation,
#         'result': result
#     })

# if __name__ == '__main__':
#     print(" Server running on http://127.0.0.1:5000")
#     app.run(host='0.0.0.0', port=5000)
# #server
# # for manually
# # http://127.0.0.1:5000/operation?number=4&operation=cube

from flask import Flask, request, jsonify
import webbrowser
import threading

app = Flask(__name__)

EXCHANGE_RATES = {
    "USD": 0.012,
    "EUR": 0.011,
    "GBP": 0.0095
}

@app.route('/')
def home():
    return '''
    <h2>💱 Currency Conversion API</h2>
    <p>Use the following format to convert:</p>
    <pre>http://127.0.0.1:5000/convert?amount=100&currency=USD</pre>
    <p>Available currencies: USD, EUR, GBP</p>
    '''

@app.route('/convert', methods=['GET'])
def convert_currency():
    amount = request.args.get('amount', type=float)
    currency = request.args.get('currency', default='USD', type=str).upper()

    if amount is None:
        return jsonify({'error': 'Please provide an amount parameter!'}), 400

    if currency not in EXCHANGE_RATES:
        return jsonify({'error': 'Invalid currency! Use USD, EUR, or GBP.'}), 400

    converted = amount * EXCHANGE_RATES[currency]
    return jsonify({
        'Amount (INR)': amount,
        'Converted Currency': currency,
        'Converted Value': round(converted, 2)
    })


def open_browser():
    # Wait a second to make sure the server starts, then open browser
    webbrowser.open("http://127.0.0.1:5000")

if __name__ == '__main__':
    threading.Timer(1.5, open_browser).start()
    print("💱 Server running on http://127.0.0.1:5000 ...")
    app.run(host='127.0.0.1', port=5000)
