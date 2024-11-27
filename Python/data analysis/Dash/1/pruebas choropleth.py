import pandas as pd
import plotly.express as px
from dash import Dash, dcc, html, Input, Output

df = pd.read_csv("intro_bees.csv")
df = df.groupby(['State', 'ANSI', 'Affected by', 'Year', 'state_code'])[['Pct of Colonies Impacted']].mean()
df.reset_index(inplace=True)
print(df.head())

app = Dash()

app.layout = html.Div([
    html.H1("Mapa de prueba!", style={'text-align': 'center'}),
    dcc.Dropdown(id="slct-year",
                 options=[
                        {"label": "2015", "value": 2015},
                        {"label": "2016", "value": 2016},
                        {"label": "2017", "value": 2017},
                        {"label": "2018", "value": 2018}
                 ],
                 multi=False,
                 value=2015,
                 style={"width": "40%"}
                ),
    html.Div(id='output-container', children=[]),
    html.Br(),
    dcc.Graph(id='bee-map', figure={})
])

@app.callback(
    [Output('output-container', 'children'),
     Output('bee-map', 'figure')],
    [Input('slct-year', 'value')]
)

def update_graph(opcion):
    print(opcion)
    container = opcion

    dff = df.copy()
    dff = dff[dff["Year"] == opcion]
    dff = dff[dff["Affected by"] == "Varroa_mites"]

    fig = px.choropleth(
        data_frame=dff,
        locationmode='USA-states',
        locations='state_code',
        scope='usa',
        color='Pct of Colonies Impacted',
        hover_data=['State', 'Pct of Colonies Impacted'],
        template='plotly_dark'
    )

    return container, fig

app.run(debug=True)
