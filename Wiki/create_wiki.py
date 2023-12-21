import os
import argparse
from datetime import date

import pandas as pd
import jinja2
from jinja2 import FileSystemLoader, pass_eval_context

today = date.today()
date = str(today)

parser = argparse.ArgumentParser()

parser.add_argument("files", nargs="+", help="CSV file paths")
parser.add_argument("--split", action="store_true", help="Split wiki into multiple pages")
parser.add_argument("--date", type=str, default=None, help="Override used date")

args = parser.parse_args()

if args.date:
    date = args.date


df = pd.DataFrame()

for fname in args.files:
    temp_df = pd.read_csv(fname)

    df = pd.concat([df, temp_df])

df.fillna("-", inplace=True)
df["Framework"] = df["Backend"].apply(lambda x: "tvm" if "tvm" in x else "tflm")

# print("df", df)
def env_var(value, key):
    return os.getenv(key, value)


def round3(value):
    return round(float(value), 3)


environment = jinja2.Environment(loader=FileSystemLoader("./"))

environment.filters["env_var"] = env_var
environment.filters["round3"] = round3

template = environment.get_template("benchmarks_template.md.j2")

data = {}

for framework_name, framework_df in df.groupby("Toolchain"):
    data[framework_name] = {}
    for toolchain_name, toolchain_df in framework_df.groupby("Framework"):
        data[framework_name][toolchain_name] = {}
        for backend_name, backend_df in toolchain_df.groupby("Backend"):
            data[framework_name][toolchain_name][backend_name] = {}
            for model_name, model_df in backend_df.groupby("Model"):
                data[framework_name][toolchain_name][backend_name][model_name] = model_df.to_dict("records")
# data = {
#     "tflmi": {
#         "aww": aww_tflmi_df.to_dict("records"),
#         "vww": vww_tflmi_df.to_dict("records"),
#         "vww": vww_tflmi_df.to_dict("records"),
#         "toycar": toycar_tflmi_df.to_dict("records"),
#     },
#     "tvmaot": {
#         "aww": aww_tvmaot_df.to_dict("records"),
#         "vww": vww_tvmaot_df.to_dict("records"),
#         "vww": vww_tvmaot_df.to_dict("records"),
#         "toycar": toycar_tvmaot_df.to_dict("records"),
#     },
# }

MODEL_DESCS = {
    "aww": "Audio Wake Words",
    "vww": "Visual Wake Words",
    "resnet": "Image Classification",
    "toycar": "Anomaly Detection",
}

BACKEND_DESCS = {
    "tfmli": "Tensorflow Lite for Microcontrollers",
    "tvmaot": "TVM",
}

if args.split:
    for framework_name, framework_data in data.items():
        for toolchain_name, toolchain_data in framework_data.items():
            filename = f"Benchmarks-" + date + "-" + framework_name.upper() + "-" + toolchain_name.upper() + ".md"
            # print("data", {framework_name: {toolchain_name: toolchain_data}})
            content = template.render(
                data={framework_name: {toolchain_name: toolchain_data}},
                model_descriptions=MODEL_DESCS,
                backend_descriptions=BACKEND_DESCS,
            )
            with open(filename, mode="w", encoding="utf-8") as message:
                message.write(content)
                print(f"... wrote {filename}")
else:
    filename = f"Benchmarks-" + date + ".md"
    # data2 = {}
    # for framework_name, framework_data in data.items():
    #     for toolchain_name, toolchain_data in framework_data.items():
    #         data2.update(toolchain_data)
    # print("data", data)
    content = template.render(
        data=data,
        model_descriptions=MODEL_DESCS,
        backend_descriptions=BACKEND_DESCS,
    )
    with open(filename, mode="w", encoding="utf-8") as message:
        message.write(content)
        print(f"... wrote {filename}")
