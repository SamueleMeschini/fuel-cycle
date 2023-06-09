import numpy as np
import matplotlib
import matplotlib.pyplot as plt
import pandas as pd
from matplotlib.patches import FancyArrowPatch
import matplotx


plt.rcParams["font.size"] = "16"
df = pd.read_csv('data/inflection_point.csv', header=None)
storage_inventory = df.iloc[:50000,0].to_numpy() 
time = df.iloc[:50000,1].to_numpy()/3600/24
t_infl = time[np.argmin(storage_inventory)]




# fig, axs = plt.subplots(nrows=2, ncols=1, sharex=True, figsize=(6,6))

# axs[0].plot(time[:20000], storage_inventory[:20000]-0.01)
# axs[0].set_ylim(0,1.6)
# axs[0].set_ylabel('$I_{storage} (kg)$')
# # ax.grid(which="major", axis="y", alpha=0.1)
# axs[0].annotate('Inflection point', xy=(t_infl, np.min(storage_inventory)),  xycoords='data',
#             xytext=(30, 1), textcoords='data',
#             arrowprops=dict(arrowstyle="->",
#                             connectionstyle="arc3"),
#             horizontalalignment='right', verticalalignment='top',
#             )   

# # Plot with reserves 
# storage_inventory += 1
# axs[1].plot(time[:20000], storage_inventory[:20000]-0.01)
# axs[1].set_xlabel('Time (days)')
# axs[1].set_ylim(0,3)
# axs[1].set_ylabel('$I_{storage} (kg)$')
# axs[1].set_yticks(np.array([0.0,1.0,2.0,3.0]))
# # ax.grid(which="major", axis="y", alpha=0.1)
# axs[1].annotate('Inflection point', xy=(t_infl, np.min(storage_inventory)),  xycoords='data',
#             xytext=(30, 2.5), textcoords='data',
#             arrowprops=dict(arrowstyle="->",
#                             connectionstyle="arc3"),
#             horizontalalignment='right', verticalalignment='top',
#             )   

# myArrow = FancyArrowPatch(posA=(t_infl, 0), posB=(t_infl, 1), arrowstyle='<|-|>', color='k',
#                           mutation_scale=10, shrinkA=0, shrinkB=0)
# axs[1].text(x=7, y = 0.5, s='Reserve inventory')
# axs[1].add_artist(myArrow)

# for ax in axs:
#     ax.spines.right.set_visible(False)
#     ax.spines.top.set_visible(False)
#     matplotx.ylabel_top("Storage \n inventory (kg)", ax=ax)
#     ax.grid(which="major", axis="y", alpha=0.1)

# plt.tight_layout()
# plt.savefig("inflection_point.pdf", dpi=300)
# plt.show()

fig, ax = plt.subplots()

ax.plot(time[:20000], storage_inventory[:20000]-0.01)
ax.set_xlabel('Time (days)')
ax.set_ylim(0,1.5)
ax.set_ylabel('Storage inventory (kg)')
ax.grid(which="major", alpha=0.1)
ax.annotate('Inflection point', xy=(t_infl, np.min(storage_inventory)),  xycoords='data',
            xytext=(30, 0.5), textcoords='data',
            arrowprops=dict(arrowstyle="->",
                            connectionstyle="arc3"),
            horizontalalignment='right', verticalalignment='top',
            )   
ax.spines.right.set_visible(False)
ax.spines.top.set_visible(False)
print(t_infl, np.min(storage_inventory))
plt.tight_layout()
plt.savefig("inflection_point_wo_reserves.eps", format='eps', dpi=300)
plt.show()

# Plot with reserves 
storage_inventory += 1
fig, ax = plt.subplots()
ax.plot(time[:20000], storage_inventory[:20000]-0.01)
ax.set_xlabel('Time (days)')
ax.set_ylim(0,3)
ax.set_ylabel('Storage inventory (kg)')
ax.grid(which="major", alpha=0.1)
ax.annotate('Inflection point', xy=(t_infl, np.min(storage_inventory)),  xycoords='data',
            xytext=(30, 2), textcoords='data',
            arrowprops=dict(arrowstyle="->",
                            connectionstyle="arc3"),
            horizontalalignment='right', verticalalignment='top',
            )   
ax.spines.right.set_visible(False)
ax.spines.top.set_visible(False)
myArrow = FancyArrowPatch(posA=(t_infl, 0), posB=(t_infl, 1), arrowstyle='<|-|>', color='k',
                          mutation_scale=10, shrinkA=0, shrinkB=0)
ax.text(x=7, y = 0.5, s='Reserve inventory')
ax.add_artist(myArrow)
plt.tight_layout()
plt.savefig("inflection_point_w_reserves.eps", format='eps', dpi=300)
plt.show()
